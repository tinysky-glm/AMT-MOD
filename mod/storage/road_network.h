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

class RoadNetwork {
 public:
  explicit RoadNetwork(const std::string& node_file, const std::string& edge_file);

  /*
   * 返回所有的路网点
   */
  const std::vector<Point>& nodes() const {
    return nodes_;
  }

 protected:
  std::vector<Point> nodes_;
  std::vector<std::vector<mod_int_t>> link_lists_; 
};

}  // namespace mod
