/*!
 * \file trajectory.cc
 * \brief The trajectory of moving object, such as taxi.
 */
#include "mod/storage/trajectory.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using  namespace mod;
Trajectory::Trajectory(const std::string& file){
    std::ifstream infile;
    std::string temp;
    int index = 0;
    infile.open(file.c_str());
    if (!infile.is_open()){
        std::cout << "未成功打开文件" << std::endl;
        exit(EXIT_FAILURE);
     }
    while(getline(infile,temp)) {
    	int i = 0;//储存轨迹点下标
        float f[2]={0.0};//存储坐标
        sscanf(temp.c_str(),"%d%*c%f%*c%f",&i ,&f[0] ,&f[1]);
	Point p(i, f[0], f[1]);
        points_.push_back(p);
        if(infile.eof())
                break;
     }
}
