/*!
 * \file passby_matching.h
 * \desc The passby trajectory and road-network matching algorithm. 
 */

#pragma once

 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"
 #include "mod/storage/trajectory.h"
 #include <vector>

 #include  <string>
 namespace mod{


    //匹配结果
    struct MatchingResult {
    	int p_index;
	int edge_id;
    };

    class PassbyMatching :public Matching{
        public:
		PassbyMatching(){};
		
		std::vector<struct MatchingResult> getPassByMatching(Index& index,const RoadNetwork& road_net_work,const Point& n_start_point);
    };
}


