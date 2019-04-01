
 #include "mod/storage/road_network.h"
 #include "mod/algorithm/index.h"
 #include "mod/algorithm/matching.h"
 #include "mod/algorithm/passby_matching.h"
 #include <vector>

 #include  <string>

 namespace mod{

   //std::vector<int> getPassByMatching(const std::unique_ptr<ISpatialIndex>& index_,const RoadNetwork& road_net_work){
   std::vector<int> PassbyMatching::getPassByMatching(Index& index,const RoadNetwork& road_net_work){
        std::vector<Point> nodes_  =road_net_work.nodes();
        //循环每一个交叉口
        std::vector<int> matching_results_;
        int i = 0;
        while(i < 10000){
            /**以某一交叉口为例*/
            //存储本次循环的结果
	    Matching m ;
            int edge_id = m.getMatchingSeg(index,nodes_[i]);
	    if(edge_id == -2  || edge_id == -1){
		break;			
  //          std::cout << "没有找到边集合" <<std::endl;
//            exit(EXIT_FAILURE);
	    }
            matching_results_.push_back(edge_id);
            int end_point =road_net_work.getEndPoint(nodes_[i],edge_id);
            //由id获取点
            Point temp_point = road_net_work.getNodeById(end_point);
            //设置下一个交叉口为这一条轨迹的终点
            i = temp_point.index;

        }
        return matching_results_;
    }


}
