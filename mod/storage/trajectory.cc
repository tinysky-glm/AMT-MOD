/*!
 * \file trajectory.cc
 * \brief The trajectory of moving object, such as taxi.
 */
#include "mod/storage/trajectory.h"
using  namespace mod;
using  namespace std;

Trajectory::Trajectory(string& file){
    ifstream infile;
    vector<Point> nodes;
    infile.open(file.c_str());
    while(getline(infile,temp, ',')) {
         Point p;
         float a[2]={0.0};
         istringstream iss;
         iss.str(temp);
         string s;
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
