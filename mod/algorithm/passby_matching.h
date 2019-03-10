/*!
 * \file passby_matching.h
 * \desc The passby trajectory and road-network matching algorithm. 
 */

#pragma once

 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"

 #include <vector>
//#常量还没定义
 namespace mod{

     class PassbyMatching{
        public:
            //返回点到轨迹片段的距离
        	double minDist(Point point ,struct SegTrajectory seg);
        	//返回所有距离点严格小于阈值的所有Edgey*
            vector<struct Edge*> getNearEdges(Point point,double threshold);
            //匹配距离点最近的Edge*
            struct Edge* getNearestEdge(Point point,double &shortestDist);
        	//初始化?轨迹段索引
        	Point init(std::vector<struct TrajectoryNode> trajectory,Point point,int index)
            //传递概率
            int pass(std::vector<struct TrajectoryNode> trajectory,Point point,int index);

     }
 }
