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
    while(getline(infile,temp, ',')) {
         float a[3]={0.0};
         std::istringstream iss;
         iss.str(temp);
         std::string s;
         int i=0;
         while (iss >> s){
            a[i]=atof(s.c_str());
            i++;
         }
	 Point p(a[1], a[2]);
         points_.push_back(p);
     }
}
