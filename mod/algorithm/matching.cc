#include "mod/algorithm/matching.h"
#include "mod/storage/road_network.h"
#include "mod/algorithm/index.h"
#include <spatialindex/SpatialIndex.h>
#include <vector>
#include "mod/storage/point.h"
#define K_VALUE 5
using namespace SpatialIndex;
using namespace SpatialIndex::RTree;
namespace mod{

    //匹配轨迹点到边缘上（就传送轨迹索引和边缘起始点
//    int RoadNetwork::getMatchingSeg(const std::unique_ptr<ISpatialIndex>& index_,const Point& start_point){
    int Matching::getMatchingSeg( Index& tra_index,const Point& start_point){
        int edge_id = -1;
        //存储终点
        Point search_seg_point;
        //查询该起始点开始的所有终点
        std::vector<Point> end_point =road_net_work.getlinklist(start_point);;

        //匹配轨迹点与每个终点，找到最符合轨迹的终点，进而查出对应edge
        for(int i = 0;i < end_point.size();i++){
            Point temp_point;
            double possible_tra_distance = 500.0;
            temp_point = tra_index.Search(end_point[i],K_VALUE,possible_tra_distance);
            if(temp_point.index == -3){
	        return -2;
	    }
	    double temp_dis = 0.0;
            if(i == 0){
                tra_point_ = temp_point;
                search_seg_point = end_point[i];
                temp_dis =  possible_tra_distance;
            }
            if(possible_tra_distance < temp_dis){
                tra_point_ = temp_point;
                search_seg_point = end_point[i];
            }
        }
	edge_id = road_net_work.getEdgeId(start_point,search_seg_point);
        if(edge_id == -1){
            std::cout << "未查询到道路网边id" <<std::endl;
	    return -1;
//            exit(EXIT_FAILURE);
        }
        return edge_id;
    }


}

