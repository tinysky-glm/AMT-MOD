/*!
 *\file matching.h
 * \desc The trajectory road-network matching algorithm.
 */

#pragma once

#include "mod/algorithm/index.h"
#include <vector>
#include <memory>
#include "mod/storage/point.h"
#include "mod/storage/trajectory.h"
#include "mod/storage/road_network.h"
#include "SpatialIndex.h"

using namespace SpatialIndex::RTree;

namespace mod{
 	//边缘
    struct Edge {
    	int   edge_index;
    	int   start_node_index;
    	int   end_node_index;
    };
    class Matching :public RoadNetwork{

        public:

		explicit Matching(){};
		
		RoadNetwork road_net_work = RoadNetwork("../../data/WA/WA_Nodes.txt", "../../data/WA/WA_Edges.txt");
	        Trajectory trajectory = Trajectory("../../data/traj/input_01.txt");

		std::vector<Point> nodes_  =road_net_work.nodes();
	        std::vector<Point> points_  =trajectory.points();
//        Index road_index = Index(nodes_);
  //      Index tra_index = Index(points_);

   public:
	     //匹配轨迹点到边缘上（就传送一个trajectory就可以）
             //virtual int getMatchingSeg(const std::unique_ptr<ISpatialIndex>& index_,const Point& start_point) = 0;
             //int getMatchingSeg(const std::unique_ptr<ISpatialIndex>& index_,const Point& start_point);
   	      int getMatchingSeg( Index& tra_index,const Point& start_point);
             //virtual int getMatchingSeg(Index index,const Point& start_point) = 0;
	     const Point tra_point() const{
		return tra_point_;
    	     }
        protected:
	    Point tra_point_;
    };
}
