
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
#include "mod/algorithm/matching_accuracy.h"
#include "gtest/gtest.h"
#define K_VALUE 5
#define THRESHOLD 500.0
namespace mod {

TEST(TestShpHelper, TestAll) {
  RoadNetwork road_net_work = RoadNetwork("../../data/WA/WA_Nodes.txt", "../../data/WA/WA_Edges.txt");
  Trajectory trajectory = Trajectory("../../data/traj/input_01.txt");
  //Index索引建立
  std::vector<Point> nodes_  =road_net_work.nodes();
  std::vector<Point> points_  =trajectory.points();
  Index n_index = Index(nodes_);
  Index p_index = Index(points_);
  double threshold = THRESHOLD;
  //初始交叉口获取
  Point n_start_point = n_index.Search(points_[0],K_VALUE,threshold);
  //获取匹配结果集
  PassbyMatching pn;
  std::vector<struct MatchingResult> results = pn.getPassByMatching(p_index,road_net_work,n_start_point);
  printf("ID\t道路边id\n");
  for(int i = 0;i<results.size();i++){
      printf("%d\t%d\n",results[i].p_index,results[i].edge_id);
  }
  //计算准确度
  MatchingAccuracy m_accuracy;
  double a_matching = m_accuracy.getMatchingAccuracy(results,"../../data/traj/output_02.txt");
  printf("Passby算法匹配准确度为%f",a_matching);
}



}
