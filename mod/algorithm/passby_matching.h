/*!
 * \file passby_matching.h
 * \desc The passby trajectory and road-network matching algorithm. 
 */

#pragma once

 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"

 #include <vector>

 #include  <string>
 namespace mod{

    //带有时间戳的轨迹点
    struct TrajectoryNode {
    	struct Point point;
    	int   timestamp;
    };

    //轨迹片段
    struct SegTrajectory {
    	int  seg_time;//经过时间
    	int  start_seg_index;
    	int  end_seg_index;
    };

    class PassbyMatching{
        public:
            explicit PassByMatching(const RoadNetwork& road_network);
            //匹配轨迹点到边缘上
            virtual std::vector<mod_int_t> getMatchingResult(const Trajectory& trajectory) = 0;
            //获取轨迹片段（存在疑惑，与交叉口匹配的轨迹点有多个，用哪个作为起点和终点）
	        ???? getTrajectorySeg(const TrajectoryNode& TNodeBegin,const TrajectoryNode& TNodeEnd);
	        //匹配结果
	        std::vector<string> getMatchingResult(const Trajectory& trajectory);
	        //匹配精确度
	        const bool getMatchingResult(std::vector<string> resultString,const std::string& output_file);

        protected: 
        	//标准正态分布函数计算传递概率
        	//std::normal_distribution<double> distribution(const float& x,const float& y);

            //返回点到轨迹片段的距离
        	const double minDist(const Point& point ,struct SegTrajectory seg);//？？？？
        	//初始化?轨迹段索引
        	//Point init(std::vector<struct TrajectoryNode> trajectory,Point point,int index)
            //传递概率

     }
 }
