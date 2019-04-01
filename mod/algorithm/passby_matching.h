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
		std::vector<struct MatchingResult> getPassByMatching(Index& index,const RoadNetwork& road_net_work);
		//std::vector<int> getPassByMatching(const std::unique_ptr<ISpatialIndex>& index_,const RoadNetwork& road_net_work);
               //explicit PassbyMatching(const RoadNetwork& road_network);
		double getMatchingAccuracy(std::vector<struct MatchingResult>& matching_results_,const std::string& file);         
    };
}
/**    //轨迹片段
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
*/

