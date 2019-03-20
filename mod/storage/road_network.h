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

  /*
   * 返回所有的路网点
   */
  const std::vector<Point>& nodes() const {
    return nodes_;
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
