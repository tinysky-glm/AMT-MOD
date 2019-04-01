/*!
 * \file road_network.h
 * \brief The road network
 */
#pragma once

#include <string>
#include <vector>

#include "mod/common/common_defines.h"
#include "mod/storage/point.h"

namespace mod {
struct Connection{
 mod_int_t point_id;
 mod_int_t edge_id;
};
class RoadNetwork {
 public:
  explicit RoadNetwork(const std::string& node_file, const std::string& edge_file);
  explicit RoadNetwork(){};
  /*
   * 返回所有的路网点
   */
  const std::vector<Point>& nodes() const {
    return nodes_;
  }
//根据点ID获取点
  const Point getNodeById(int index) const{
	return nodes_[index];
  }
//根据点获取由此点开始的边结束点  
  const std::vector<Point> getlinklist(Point p) const {

        std::vector<Point> end_points_;
	end_points_.clear();
	for(int i =0;i < link_lists_[p.index].size();i++)
        {
	     int index = link_lists_[p.index][i].point_id;
             end_points_.push_back(this->getNodeById(index));
        }
	return end_points_;
  }
  const int getEdgeId(Point s_point,Point e_point) const{
	for(int i = 0;i < link_lists_[s_point.index].size();i++){
             if(link_lists_[s_point.index][i].point_id == e_point.index){
                 return link_lists_[s_point.index][i].edge_id;
             }
	}
}

const int getEndPoint(Point s_point,int Edge_id) const{
	
	for(int i = 0;i < link_lists_[s_point.index].size();i++){
             if(link_lists_[s_point.index][i].edge_id == Edge_id){
                 return link_lists_[s_point.index][i].point_id;
             }
	}
}

  const std::vector<struct Connection>& link_list(size_t index) const {
    return link_lists_[index];
  }

 protected:
  // point0 point1 point2
  std::vector<Point> nodes_;
  // [[1, 2], [0], [0]]
  std::vector<std::vector<struct Connection>> link_lists_; 
  
};

}  // namespace mod
