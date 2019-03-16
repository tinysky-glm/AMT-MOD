/*!
 *\file matching.h
 * \desc The trajectory road-network matching algorithm.
 */

 #pragma once

 #include "mod/algorithm/index.h"
 #include <vector>

 namespace mod{
 	//边缘
    struct Edge {
    	int   edge_index;
    	int   start_node_index;
    	int   end_node_index;
    };
    class Matching{

        public:
	     explicit Matching(const RoadNetwork& road_network);
	     //根据索引下标返回正确的边
	     Edge getEdges(const mod_int_t index);
	     //返回所有匹配的id
	     std::vector<int> getMatchingIndex(const Point& pointBegin,const Point& pointEnd);
	     //匹配轨迹点到边缘上（就传送一个trajectory就可以）
	     virtual std::vector<mod_int_t> getMatchingSeg(const Trajectory& trajectory) = 0;
    };
 }

