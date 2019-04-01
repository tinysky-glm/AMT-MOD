
/*
 * \file shp_helper_test.cc
 * \desc The shp helper test unit
 */
#include "mod/utils/txt2shp.h"
#include "mod/storage/road_network.h"
#include "mod/storage/trajectory.h"
#include "mod/algorithm/index.h"
#include "mod/algorithm/matching.h"
#include "mod/algorithm/passby_matching.h"
#include "gtest/gtest.h"

namespace mod {

TEST(TestShpHelper, TestAll) {
  RoadNetwork road_net_work = RoadNetwork("../../data/WA/WA_Nodes.txt", "../../data/WA/WA_Edges.txt");

  Trajectory trajectory = Trajectory("../../data/traj/input_01.txt");
 // std::vector<struct MatchingResult> results = PassByMatching(road_net_work,trajectory);
 
  //Index下函数测试
  std::vector<Point> nodes_  =road_net_work.nodes();
  std::vector<Point> points_  =trajectory.points();
  Index n_index = Index(nodes_);
  Index p_index = Index(points_);
/**double s = 500.0;
 Point t_point = p_index.Search(nodes_[0],5,s);
  printf("\n%d****%f*****%f",t_point.index,t_point.lon,t_point.lat);
*/
//matching下函数测试
/**Matching m;
int edge_id = m.getMatchingSeg(p_index,nodes_[43]);
printf("matching下函数测试getEdge	%d",edge_id);*/
//passBymatching下函数测试
PassbyMatching pn;
std::vector<int> edges = pn.getPassByMatching(p_index,road_net_work);
for(int i = 0;i<edges.size();i++){
	printf("passBymatching下函数测试	  %d",edges[i]);
	
}


 //int edge_id = m.getMatchingSeg(n_index,points_[0]);

/**
  //验证道路网点的获取
  std::vector<Point> nodes_  =road_net_work.nodes();
  for(int j=0;j<nodes_.size();j++)
  {
     printf("nodeLon: %f\tnodeLat:%f\tnodeIndex:%d\n",nodes_[j].lon,nodes_[j].lat,nodes_[j].index);
  }
*/

/**
//验证道路网邻接表
for(int i =0;i < link_lists_.size();i++)
{
  std::vector<struct Connection> conns = road_net_work.link_list(i);
  for(int j=0;j<conns.size();j++)//遍历出发点所引出的边
  {
     printf("from %d to %d,the edge_id is %d\n",i,conns[j].point_id,conns[j].edge_id);
  }
}
*/
  

/**
  //验证轨迹点的获取
  std::vector<Point> points_  =trajectory.points();
  for(int j=0;j<points_.size();j++)
  {
     printf("pointLon: %f\tpointLat:%f\tpointIndex:%d\n",points_[j].lon,points_[j].lat,points_[j].index);
  }
*/
}



}  // namespace mod
