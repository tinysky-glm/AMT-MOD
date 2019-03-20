/*
 * \file shp_helper_test.cc
 * \desc The shp helper test unit
 */
#include "mod/utils/txt2shp.h"
#include "mod/storage/road_network.h"
#include "mod/storage/trajectory.h"


#include "gtest/gtest.h"

namespace mod {

TEST(TestShpHelper, TestAll) {
  RoadNetwork road_net_work = RoadNetwork("../../data/WA/WA_Nodes.txt", "../../data/WA/WA_Edges.txt");

  Trajectory trajectory = Trajectory("../../data/traj/input_01.txt");

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
