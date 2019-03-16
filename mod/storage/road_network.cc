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
        float f[3]={0.0};
        std::istringstream iss;
        iss.str(temp);
        std::string s;
        int i=0;
        while (iss >> s){
            f[i] = atof(s.c_str());
            i++;
        }
      Point p(f[1], f[2]);
      nodes_.push_back(p);
    }


    //读取交叉口点
    int index = 0;
    //邻接矩阵初始化
    for(int i=0;i < nodes_.size();i++) 
    {
        std::vector<mod_int_t> vec(nodes_.size(),0);
        link_lists_.push_back(vec);
    }
    infile.open(edge_file.c_str());  //infile按照指定路径读取txt文件
    if (!infile.is_open()){
       std::cout << "未成功打开文件" <<std::endl;
       exit(EXIT_FAILURE);
     }
    while(getline(infile,temp)) {
        int a[4]={0};//文件中4个数值
        std::stringstream iss;//istringstream读 string
        iss.str(temp);//temp 复制给 iss
        std::string s;
        int i=0;
        while (iss >> s){
            a[i] = atoi(s.c_str());
            i++;
        } 
        link_lists_[a[1]][a[2]]=1;
        link_lists_[a[2]][a[1]]=1;
    }
}
