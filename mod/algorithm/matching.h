/*!
 *\file matching.h
 * \desc The trajectory road-network matching algorithm.
 */

#pragma once

#include "mod/algorithm/index.h"
#include <vector>
#include <memory>
#include "mod/storage/point.h"
#include "SpatialIndex.h"

using namespace SpatialIndex::RTree;

namespace mod{
 	//边缘
    struct Edge {
    	int   edge_index;
    	int   start_node_index;
    	int   end_node_index;
    };
    class Matching{

        public:
	     //匹配轨迹点到边缘上（就传送一个trajectory就可以）
             virtual int getMatchingSeg(const std::unique_ptr<ISpatialIndex>& index_,const Point& start_point) = 0;

        protected:
            std::unique_ptr<IStorageManager> storage_;
            std::unique_ptr<ISpatialIndex> index_;
	    const std::vector<Point> * points_;
	    const Point  tra_point_;
    }
}
