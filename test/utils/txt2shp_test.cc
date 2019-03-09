/*
 * \file shp_helper_test.cc
 * \desc The shp helper test unit
 */
#include "/mod/utils/txt2shp.h"
//#include "/mod/storage/road_network.h"
#include "/mod/storage/trajectory.h"


#include "/gtest/gtest.h"

namespace mod {

TEST(TestShpHelper, TestAll) {

}
int main(){
    RoadNetwork("data/WA/WA_Edges.txt","data/WA/WA_Nodes.txt");
    Trajectory("data/traj/input_01.txt");
    return 0;
}

}  // namespace mod
