/*!
* \file road_network.cc
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
    int index;
    std::string temp;
    //读取交叉口点
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
             a[i] = stoi(s);
             i++;
         }
       link_lists_[a[1]][a[2]] = a[3];
     }

     //顶点
     const int NODE_LENGTH = 600000;
     infile.open(node_file.c_str());
     if (!infile.is_open()){
            std:: cout << "未成功打开文件" << std::endl;
      }
     nodes_.resize(NODE_LENGTH);
     while(getline(infile,temp)) {
         // Node p;
          float f[3]={0.0};
          std:: istringstream iss;
          iss.str(temp);
          std::string s;
          int i=0;
          while (iss >> s){
              f[i] = atof(s.c_str());
              i++;
          }
        Point p(f[1], f[2]);
        nodes_[f[0]] = p;
      }

}

