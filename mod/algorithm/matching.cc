#include "mod/algorithm/matching.h"
#include "mod/storage/road_network.h"
#include "mod/algorithm/index.h"
#include <spatialindex/SpatialIndex.h>
#include <vector>
#include<algorithm>
#include "mod/storage/point.h"
#define K_VALUE 5
#define PI 3.14159265
#define DEG2RAD(degree) (degree * PI) / 180.0
#define EARTH_RADIUS 6378.137
using namespace SpatialIndex;
using namespace SpatialIndex::RTree;
namespace mod{
    //匹配轨迹点到边缘上（就传送轨迹索引和边缘起始点
    int Matching::getMatchingSeg( Index& tra_index,const Point& start_point,Point& tra_point_){
        int edge_id = -1;
        //存储终点
        Point search_seg_point;
        //查询该起始点开始的所有终点
        std::vector<Point> end_point =road_net_work.getlinklist(start_point);
	double possible_tra_distance = 500.0;	
	//初始边起点对应的轨迹点
	Point start_tra_point = tra_index.Search(start_point,K_VALUE,possible_tra_distance);
        printf("最初起点对应轨迹点的id=%d\n",start_tra_point.index);
	double temp_dis = 0.0;
	//通过轨迹点下标判断可能的边终点
	int min_index = 0;
	search_seg_point = end_point[0];
	//获取和起点轨迹点距离最近的轨迹点（即最有可能的终点轨迹点）
	int tra_distance =0;
	//用来判断的距离
	double min_distance = 0.0;
	double temp_set_distance=0.0;
	//TEST:增加一个判断条件
	int j = 0;
        //匹配轨迹点与每个终点，找到最符合轨迹的终点，进而查出对应edge
        for(int i = 0;i < end_point.size();i++){
            Point temp_point;
            temp_point = tra_index.Search(end_point[i],K_VALUE,possible_tra_distance);
	    if(i == 0) min_index = temp_point.index;
	    //作为判断依据，这个距离必须大于0
	    tra_distance = temp_point.index - start_tra_point.index;
	    //获取轨迹点不合条件，退出！！
            if(temp_point.index == -3){
	        return -2;
	    }
	    else if(tra_distance >1){
		if(j==0) min_distance = tra_distance;
		if(min_distance > tra_distance || min_distance == tra_distance){
			search_seg_point = end_point[i];
			tra_point_ = temp_point;
			min_index = temp_point.index;
			min_distance = tra_distance;
		}
		j++;
	    }
	}
	printf("结束后的终点为多少？%d\n",search_seg_point.index);
			//TEST:
	printf("结束后终点对应轨迹点下标为多少？%d\n",tra_point_.index);
	edge_id = road_net_work.getEdgeId(start_point,search_seg_point);
        if(edge_id == -1){
            std::cout << "未查询到道路网边id" <<std::endl;
	    return -1;
        }
        return edge_id;
    }



}

