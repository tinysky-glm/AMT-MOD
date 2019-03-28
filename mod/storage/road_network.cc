/*!




*\file road_network.cc
* \brief The road network
*/
#include "mod/storage/road_network.h"

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace mod;
RoadNetwork::RoadNetwork(const std::string& node_file,const std::string& edge_file){

    std:: ifstream infile;
    std::string temp;
    //顶点
    infile.open(node_file.c_str());
    if (!infile.is_open()){
        std:: cout << "未成功打开文件" << std::endl;
    }
    while(getline(infile,temp)) {
	int i =0;
	float f[2]={0.0};
        sscanf(temp.c_str(),"%d %f %f",&i ,&f[0] ,&f[1]);
        Point p(i, f[0], f[1]);
        nodes_.push_back(p);
	if(infile.eof())
		break;
    }


    //读取交叉口点
    int index = 0;
    std::ifstream infile1;
    temp ="";
    link_lists_.resize(nodes_.size());
    infile1.open(edge_file.c_str());  //infile按照指定路径读取txt文件
    if (!infile1.is_open()){
       std::cout << "未成功打开文件" <<std::endl;
       exit(EXIT_FAILURE);
     }
     while(getline(infile1,temp)) {
 	int a = 0;//存储起点id
	Connection conn= {0,0};//存储终点和边的id
	sscanf(temp.c_str(),"%d %d %d %*s",&conn.edge_id,&a,&conn.point_id);        
	//
	//printf(" *********from %d   to  %d edge %d \n",a,conn.point_id,conn.edge_id);
	link_lists_[a].push_back(conn);
	std::swap(a,conn.point_id);
	link_lists_[a].push_back(conn);
	if(infile1.eof())
		break;
    }
}
