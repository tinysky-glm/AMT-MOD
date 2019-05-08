
 #include "mod/storage/road_network.h"
 #include "mod/storage/trajectory.h"
 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"
 #include "mod/algorithm/passby_matching.h"
 #include <vector>
#include <algorithm>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <sstream>
 #include  <string>
 #define K_VALUE 5
 #define THRESHOLD 500.0
 #define CYCLE 507936
 namespace mod{
    std::vector<struct MatchingResult> PassbyMatching::getPassByMatching(Index& index,const RoadNetwork& road_net_work,const Point& n_start_point){
        std::vector<Point> nodes_  =road_net_work.nodes();
        //循环每一个交叉口
        std::vector<struct MatchingResult> matching_results_;
        int j = 0,i = n_start_point.index;
	//存储可能终点id
	int roll_back;
	std::vector<int> candidate_end_point_id;
	while(i < CYCLE){
            /**以某一交叉口为例*/
            //测试
            printf("循环次数:%d\n",j);
	    roll_back = i;
            j++;
            //存储本次循环的结果
            struct MatchingResult re_matching_result;
            //道路边的id
            Matching m ;
	    //轨迹段的终点
            Point end_tra_point;
	    printf("这里是PassbyMatching方法！！\n");
            int edge_id = m.getMatchingSeg(index,nodes_[i],end_tra_point);
	    printf("-------PassbyMatching方法-----end---！！\n");
            //已知交叉口，循环轨迹点找最近,找到轨迹段起点
            double threshold = THRESHOLD;
            Point start_tra_point = index.Search(nodes_[i],K_VALUE,threshold);
            
            int end_point =road_net_work.getEndPoint(nodes_[i],edge_id);
            //由id获取终点
            Point temp_point = road_net_work.getNodeById(end_point);
	    //设置下一个交叉口为这一条轨迹的终点
            i = temp_point.index;
            if(edge_id == -2  || edge_id == -1){
                continue;
             }
	
            else{
                //匹配本段上的所有轨迹点并存储起来
                for(int id = start_tra_point.index;id < end_tra_point.index; id++){
                    //匹配到的边
                    re_matching_result.edge_id = edge_id;
                    re_matching_result.p_index = id;
                    matching_results_.push_back(re_matching_result);
                }
            }
        }
       	return matching_results_;
    }
 
}
