/*!
* \file road_network.cc
* \brief The road network
*/
#include "mod/storage/road_network.h"

nclude <string>
#include <vector>
use namespace std;
use namespace mod;
RoadNetwork::RoadNetwork(string& node_file,string& edge_file){

    ifstream infile;
    int index;
    string temp;
    //读取交叉口点
    infile.open(edge_file.c_str());  //infile按照指定路径读取txt文件
    if (!infile.is_open()){
        cout << "未成功打开文件" << endl;
     }
    while(getline(infile,temp)) {
         int a[4]={0};//文件中4个数值
         istringstream iss;//istringstream读 string
         iss.str(temp);//temp 复制给 iss
         string s;
         int i=0;
         while (iss >> s){
             a[i] = stoi(s);
             i++;
         }
       link_lists_[a[1]][a[2]] = a[3];
     }

     //顶点
     infile.open(node_file.c_str());
     if (!infile.is_open()){
             cout << "未成功打开文件" << endl;
      }
     while(getline(infile,temp)) {
          Node p;
          float f[3]={0.0};
          istringstream iss;
          iss.str(temp);
          string s;
          int i=0;
          while (iss >> s){
              f[i] = atof(s.c_str());
              i++;
          }
        Point p(f[1], f[2]);
        nodes[f[0]] = p;
      }

}

