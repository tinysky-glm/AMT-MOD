#include "mod/storage/road_network.h"
#include "mod/algorithm/index.h"
#include "SpatialIndex.h"
#include "capi/sidx_impl.h"
#include <vector>
#include<cmath>
#include "mod/storage/point.h"


#define PI 3.14159265
#define DEG2RAD(degree) (degree * PI) / 180.0
#define EARTH_RADIUS 6378.137

namespace mod{

    //这里关于这个Point里面还有id，故考虑用先传过来在赋值
    void insert_point(SpatialIndex::ISpatialIndex* index, Point p) {
        id_type id = p.index;
        double  pCoords[] = {p.lon,p.lat};
        index->insertData(0, nullptr, SpatialIndex::Point(pCoords, 2), id);
    }

   inline double lbs_distance(double lon1, double lat1, double lon2, double lat2) {
        double rad_lat1 = DEG2RAD(lat1);
        double rad_lat2 = DEG2RAD(lat2);

        double a = rad_lat1 - rad_lat2;
        double b = DEG2RAD(lon1) - DEG2RAD(lon2);

        double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(rad_lat1) * cos(rad_lat2) * pow(sin(b / 2), 2)));
        s = s * EARTH_RADIUS;
        return s * 1000;
    } //获取交叉点
    Index::Index(const std::vector<Point>& points):points_(&points){
        id_type id = 0;//下面函数用到的
        //只能移动的指针
        storage_.reset(StorageManager::createNewMemoryStorageManager());
        //选择填充因子,索引节点和叶子节点的容量,维度
        index_.reset(createNewRTree(*storage_, 0.7, 100, 100, 2, RV_RSTAR, id));

        if (!index_->isIndexValid()) {
            throw std::runtime_error("建立索引失败");
        }
        //插入数据
        for(std::vector<Point>::const_iterator j = points.begin();j!=points.end();j++){
            insert_point(index_.get(), (*j));
        }
    }

  
    // 寻找以交叉口为圆心，给定半径内的轨迹点
    Point Index::Search(const Point& point,int search_num,double& threshold){
	Point t_point;
        ObjVisitor * visitor = new ObjVisitor;
        auto k = search_num;
        double pCoord[] = {point.lon, point.lat};
        index_->nearestNeighborQuery(k, SpatialIndex::Point(pCoord, 2), *visitor);

        std::vector<SpatialIndex::IData *> & results = visitor->GetResults();

	int i = 0;
	//存储获取的两点距离
        double distance = threshold;
	//double min_dis = 0.0;
        for (const auto * item : results) {
            
            //获取形状即交叉点的ID
            id_type id = item->getIdentifier();
            //获取通用形状对象
            SpatialIndex::IShape * shape;
            item->getShape(&shape);
            //将形状转换为Point
            SpatialIndex::Point center;
            shape->getCenter(center);
	    double s = lbs_distance(center.m_pCoords[0],center.m_pCoords[1],point.lon, point.lat);
            //初始时
	    if(s > 1000){
		continue;
	    }
            //存储距离最小的点用来返回,这里distance用来控制保证选出最小的距离
            if(s < distance && s < threshold){
		float lon = (float)center.m_pCoords[0];
		float lat = (float)center.m_pCoords[1];
                t_point = Point((int)id,lon,lat);
		distance = s;//控制distance为最小距离
            }
            
        }
        printf("距离交叉口%d最近的轨迹点index= %d\n",point.index,t_point.index);
        if(abs(t_point.lon) <= 1e-15){
            std::cout << "未查询到距离交叉口最近的轨迹点" <<std::endl;
	    Point p = Point(-3,0.0,0.0);
	    printf("未查询到距离交叉口最近的轨迹点--ID：%d,坐标:%f\n",p.index,p.lat);
	    return p;
        }
        return t_point;
    }
}
