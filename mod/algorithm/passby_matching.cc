
 #include "mod/storage/road_network.h"
 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"
 #include "mod/algorithm/passby_matching.h"
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <sstream>
 #include  <string>
 #define K_VALUE 5
 #define THRESHOLD 500.0
 namespace mod{

    std::vector<struct MatchingResult> PassbyMatching::getPassByMatching(Index& index,const RoadNetwork& road_net_work){
        std::vector<Point> nodes_  =road_net_work.nodes();
        //循环每一个交叉口
        std::vector<struct MatchingResult> matching_results_;
        int j = 0,i = 0;
        while(i < nodes_.size()){
            /**以某一交叉口为例*/
            //测试
            printf("$$$$$%d$$$",j);
            j++;
            //存储本次循环的结果
            struct MatchingResult re_matching_result;
            //道路边的id
            Matching m ;
            int edge_id = m.getMatchingSeg(index,nodes_[i]);
            //已知交叉口，循环轨迹点找最近,找到轨迹段起点
            double threshold = THRESHOLD;
            Point start_tra_point = index.Search(nodes_[i],K_VALUE,threshold);
            //轨迹段的终点
            Point end_tra_point = Matching::tra_point();
            int end_point =road_net_work.getEndPoint(nodes_[i],edge_id);
            //由id获取点
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
                    re_matching_result.edge_id = id;
                    matching_results_.push_back(re_matching_result);
                }
            }
        }
        return matching_results_;
    }
   bool equCompare(struct MatchingResult matching ,struct MatchingResult output){
        if(matching.p_index == output.p_index && matching.p_index == output.p_index)
          return true;
        else
          return false;
   }   
   double getMatchingAccuracy(std::vector<struct MatchingResult> matching_results_,const std::string& file){
        std::ifstream infile;
        std::string temp;
        infile.open(file.c_str());
        if (!infile.is_open()){
            std::cout << "未成功打开文件" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::vector<struct MatchingResult> output_results_;
        while(getline(infile,temp)) {
	    struct MatchingResult o_result_;
            sscanf(temp.c_str(),"%d%*c%d%*c",&o_result_.p_index,&o_result_.edge_id);
	    output_results_.push_back(o_result_);
            if(infile.eof())
                    break;
        }
	int equ = 0,a_num = 0;	
	std::vector<int>  accuracy_result_;
	if(output_results_.size() == matching_results_.size()){
		for(int i = 0;i<matching_results_.size();i++){
			equ = (int)equCompare(matching_results_[i],output_results_[i]);
			if(equ)
				a_num++;
			accuracy_result_.push_back(equ);	
		}


	}
	double r_matching = (a_num*1.0)/ matching_results_.size();
	/**
	for(int i = 0;i < output_results_.size();i++){
		struct MatchingResult o_result_ = output_results_[i];
		printf("$$$$$%d$$$%d\n",o_result_.p_index,o_result_.edge_id);

	}
*/
        return r_matching;

  }

//std::vector<int> getPassByMatching(const std::unique_ptr<ISpatialIndex>& index_,const RoadNetwork& road_net_work){
   /**std::vector<int> PassbyMatching::getPassByMatching(Index& index,const RoadNetwork& road_net_work){
        std::vector<Point> nodes_  =road_net_work.nodes();
        //循环每一个交叉口
        std::vector<struct MatchingResult> matching_results_;
        int i = 0,j=0;
        while(i < nodes_.size()){
            //以某一交叉口为例
	    //测试
            printf("$$$$$%d$$$",j);
	    j++;
            //存储本次循环的结果
	    Matching m ;
            int edge_id = m.getMatchingSeg(index,nodes_[i]);
            int end_point =road_net_work.getEndPoint(nodes_[i],edge_id);
            //由id获取点
            Point temp_point = road_net_work.getNodeById(end_point);
            //设置下一个交叉口为这一条轨迹的终点
            i = temp_point.index;
            //std::cout << "没有找到边集合" <<std::endl;
            //exit(EXIT_FAILURE);

	    if(edge_id == -2  || edge_id == -1){
		continue;	
	     }
	    else{
		matching_results_.push_back(edge_id);
	    }	
        }
        return matching_results_;
    }
*/
}
