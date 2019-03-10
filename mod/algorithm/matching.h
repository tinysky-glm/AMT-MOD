/*!
 * \file matching.h
 * \desc The trajectory road-network matching algorithm.
 */

#pragma once

 #include "mod/algorithm/index.h"

 #include <vector>
 namespace mod{
    //匹配结果
     struct Result{
        struct TrajectoryNode t_point;
        struct Edge t_edge;
      }
      //结果集
      std::vector<struct Result> matching_result;

      //匹配准确度
      //（int 数组）???
      float accuracy;

      class Matching{
          public:
              Matching();
              //匹配轨迹点到边缘上
              std::vector<struct Result> getMatchingResult(std::vector<struct TrajectoryNode> trajectory,struct Edge *edge,int index);
              //计算准确度
              float accuracy(std::vector<struct Result> matching_result,std::vector<struct Result> truth_result);
          };
 }
