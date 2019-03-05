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
    vector<Point> nodes;
    infile.open(file.c_str());
    if (!infile.is_open()){
        std::cout << "未成功打开文件" << std::endl;
        exit(EXIT_FAILURE);
     }
    while(getline(infile,temp, ',')) {
         Point p;
         float a[2]={0.0};
         std::istringstream iss;
         iss.str(temp);
         std::string s;
         int i=0;
         while (iss >> s){
            a[i]=aotf(s.c_str());
            i++;
         }
         p.lat = a[1];
         p.lon = a[2];
         nodes[a[0]]=p;
     }
}
