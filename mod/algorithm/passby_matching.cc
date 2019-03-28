

 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"
 #include "mod/algorithm/passby_matching.h"
 #include <vector>

 #include  <string>
 namespace mod{

   std::vector<struct MatchingResult> PassByMatching(const RoadNetwork& road_network,const Trajectory& trajectory){
        std::vector<Point> nodes_  =road_network.nodes();
        std::vector<Point> points_  =trajectory.points();
        Index road_index = Index(nodes_);
        Index tra_index = Index(points_);
        //循环每一个交叉口
        std::vector<struct MatchingResult> matching_results_;
        int index = 0,i = 0;
        while(i < nodes_.size() && i == nodes_.size()){
            /**以某一交叉口为例*/
            //存储本次循环的结果
            struct MatchingResult re_matching_result;
            //存储匹配到某一个边上的所有轨迹点
            std::vector<Point> trajectory_point_segs;
            //道路边的起点id
            struct Edge edge;
            edge.start_node_index = nodes_[i].index;
            //第一步是已知交叉口，循环轨迹点找最近,找到轨迹段起点
            Point start_tra_point = tra_index.Search(nodes_[i])；
            //找到轨迹段匹配的边id
            int edge_id = getMatchingSeg(tra_index,nodes_[i]);
            edge.id = edge_id;
            Point end_tra_point = tra_point_;
            //匹配本段上的所有轨迹点
            for(int i = 0;i < points_.size() ; i++){
                if(points_[i].index <end_tra_point.index && points_[i].index > start_tra_point.index){
                    trajectory_point_segs.push_back(points_[i]);
                }
                if(points_[i].index > end_tra_point.index)
                    break;
            }
            //获取道路网下一个交叉口
            if(link_lists_[nodes_[i]].edge_id == edge_id){
                edge.end_node_index = link_lists_[nodes_[i]].point_id;
            }
            index++;
            //将获取到得边及其上的轨迹点添加到匹配结果中(这里写法是错误的)
            re_matching_result.index = index;
            re_matching_result.edge = edge;
            re_matching_result.tra_points_ = trajectory_point_segs;
            matching_results_.push_back(re_matching_result);
            //由id获取点
            Point temp_point;
            for(int j = 0 ;j <nodes_.size();j++){
                if(edge.end_node_index == nodes_[j].index)
                   temp_point  =  nodes_[j]
            }
            //设置下一个交叉口为这一条轨迹的终点
            nodes[++i] = temp_point;
        }
        return matching_results_;
    }


}
/**    //轨迹片段
    struct SegTrajectory {
    	int  seg_time;//经过时间
