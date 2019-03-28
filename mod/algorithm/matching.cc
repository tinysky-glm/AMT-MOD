#include "mod/storage/road_network.h"
#include "mod/algorithm/index.h"
#include <spatialindex/SpatialIndex.h>
#include <vector>

#define K_VALUE 5
using namespace SpatialIndex;
using namespace SpatialIndex::RTree;

namespace mod{

    //匹配轨迹点到边缘上（就传送轨迹索引和边缘起始点）
    int getMatchingSeg(const std::unique_ptr<ISpatialIndex>& index_,const Point& start_point){
        int edge_id = -1;
        //存储终点
        Point search_seg_point;
        //查询该起始点开始的所有终点
        std::vector<Point> end_point;
  	std::vector<Point> nodes_= nodes();
	std::vector<std::vector<struct Connection>> link_lists_; 
  	for(int i = 0;i <nodes_.size();i++){
	     link_lists_.push_back(link_lists(nodes_[i].index));
	}
        for(int i =0;i < link_lists_[start_point.index].size();i++)
        {   
            int index = link_lists_[start_point.index].point_id;
            for(int j=0;j<nodes_.size();j++){
                if(index = nodes_[j].index){
                    end_point.push_back(nodes_[j]);
                }
            }
        }
        //匹配轨迹点与每个终点，找到最符合轨迹的终点，进而查出对应edge
        for(int i = 0;i < end_point.size();i++){
            Point temp_point;
            double possible_tra_distance = 500.0;
            temp_point = index_.Search(end_point[i],K_VALUE,possible_tra_distance);
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
        if(link_lists_[start_point.index].point_id == search_seg_point.index){
            edge_id = link_lists_[start_point.index].edge_id;
        }
        if(edge_id = -1){
            std::cout << "未查询到道路网边id" <<std::endl;
            exit(EXIT_FAILURE);
        }
        return edge_id;
    }
}

