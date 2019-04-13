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
	int min_distance = 0;
//TEST:增加一个判断条件
int j = 0;
	//TEST:printf("初始化的终点为多少？%d\n",end_point[0].index);
        //匹配轨迹点与每个终点，找到最符合轨迹的终点，进而查出对应edge
        for(int i = 0;i < end_point.size();i++){
            Point temp_point;
            temp_point = tra_index.Search(end_point[i],K_VALUE,possible_tra_distance);
	    if(i == 0) min_index = temp_point.index;
	     //TEST:printf("通过距离获取到的重点对应id=%d\n",temp_point.index);
	    //作为判断依据，这个距离必须大于0
	    tra_distance = temp_point.index - start_tra_point.index;
	    //获取轨迹点不合条件，退出！！
            if(temp_point.index == -3){
	        return -2;
	    }
//TEST:else if(min_index > temp_point.index && start_tra_point.index temp_point.index){
//TEST:else if(min_index > temp_point.index && min_distance > tra_distance && start_tra_point.index !=temp_point.index){
//TEST:else if(start_tra_point.index < temp_point.index && min_distance > tra_distance){

	    else if(tra_distance >0){
		if(j==0) min_distance = tra_distance;
		if(min_distance > tra_distance || min_distance == tra_distance){
			search_seg_point = end_point[i];
			//TEST:printf("交换过程中终点为多少？%d\n",end_point[i].index);
			min_index = temp_point.index;
			min_distance = tra_distance;
		}
		j++;
	    }
	    /**if(i == 0){
		min_index = temp_point.index;
		if(tra_distance > 0){
		     min_distance = tra_distance;		
		}
	    }*/
	    /**printf("possible_tra_distance:%f!!!!!!!!\n",possible_tra_distance);
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
	//通过轨迹点下标判断可能的边终点
	int min_index = possible_tra_point[0].index;
	tra_point_ = possible_tra_point[0];
        search_seg_point = end_point[0];
	for(int i = 1;i < possible_tra_point.size();i++){
		if(min_index > possible_tra_point[i].index){
			min_index = possible_tra_point[i].index;
			tra_point_ = possible_tra_point[i];
			search_seg_point = end_point[i];
		}
	}*/
	}
	printf("结束后的终点为多少？%d\n",search_seg_point.index);
	edge_id = road_net_work.getEdgeId(start_point,search_seg_point);
        if(edge_id == -1){
            std::cout << "未查询到道路网边id" <<std::endl;
	    return -1;
//            exit(EXIT_FAILURE);
        }
        return edge_id;
    }


}

