/*!
 * \file matching.h
 * \desc The trajectory road-network matching algorithm.
 */

#pragma once

 #include "mod/algorithm/index.h"

 #include <vector>
 namespace mod{
      class Matching{
          public:
              explicit Matching(const RoadNetwork& road_network);
              //匹配轨迹点到边缘上
              virtual std::vector<mod_int_t> getMatchingResult(const Trajectory& trajectory) = 0;
          };
 }
