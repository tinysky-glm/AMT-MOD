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
    //const int POINTS_LENGTH = 3000;
    int index = 0;
    infile.open(file.c_str());
    if (!infile.is_open()){
        std::cout << "未成功打开文件" << std::endl;
        exit(EXIT_FAILURE);
     }
     char c;
     while(infile.get(c))
     {
          if(c='\n')
             index++;
     }
    // std::cout << "*******index*******=****" << index <<std::endl;
    std::cout << "*******index*******=****" << index <<std::endl;
    points_.resize(index+1);
    while(getline(infile,temp, ',')) {
         //Point p = {0,0};
         float a[2]={0.0};
         std::istringstream iss;
         iss.str(temp);
         std::string s;
         int i=0;
         while (iss >> s){
           // a[i]=aotf(s.c_str());
            a[i] = stoi(s);
            i++;
         }
	 Point p(a[1], a[2]);
         //p.lat = a[1];
         //p.lon = a[2];
         points_[a[0]] = p;
     }
}
