#pragma once

#include <memory>
#include "mod/storage/point.h"
#include "mod/storage/road_network.h"
#include "mod/storage/trajectory.h"
#include "SpatialIndex.h"
#include <vector>


using namespace SpatialIndex;
using namespace SpatialIndex::RTree;

namespace mod{

    class Index {

        public:

 	// RoadNetwork road_net_work = RoadNetwork("../../data/WA/WA_Nodes.txt", "../../data/WA/WA_Edges.txt");
 	 //Trajectory trajectory = Trajectory("../../data/traj/input_01.txt");
	//获取交叉点
	
	 explicit Index(const std::vector<Point>& points);
	// 寻找以交叉口为圆心，给定半径内的轨迹点
	Point Search(const Point& point, int search_num, double& threshold);
	/**const std::unique_ptr<ISpatialIndex> index() const{
	      return index_;
	}*/

        //std::unique_ptr<ISpatialIndex> index_;
   protected:
        //只能移动的指针
        std::unique_ptr<IStorageManager> storage_;
        //选择填充因子,索引节点和叶子节点的容量,维度
        std::unique_ptr<ISpatialIndex> index_;
	const std::vector<Point> * points_;
    };
}

