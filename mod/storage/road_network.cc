/*!
* \file road_network.cc
* \brief The road network
*/
#include "mod/storage/road_network.h"

nclude <string>
#include <vector>
use namespace std;
use namespace mod;

//指针指向？？？？？int？？？？？
struct Edge    //边
{
     int eId;
     int eStart;
     int eEnd;
     int edgelength;
     Edge *next;
};
    vector<Edge> edges;
struct Node    //道路网顶点结构体
{
     int nId;
     float nlat;
     float nlon;
     Edge *firstEdge;
}

    vector<Node> nodes;

    vector<Node> roadNodes;
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
         Edge e;
         int a[4]={0};//结构体中四个成员
         istringstream iss;//istringstream读 string
         iss.str(temp);//temp 复制给 iss
         string s;
         int i=0;
         while (iss >> s){
             a[i] = s;
             i++;
         }
         e.eId = a[0];
         e.eStart = a[1];
         e.eEnd = a[2];
         e.edgelength = a[3];
         edges.push_back(e);
     }

     //顶点
     infile.open(node_file.c_str());
     if (!infile.is_open()){
             cout << "未成功打开文件" << endl;
      }
     while(getline(infile,temp)) {
          Node p;
          float a[3]={0.0};//还要再添加吗？？？
          istringstream iss;
          iss.str(temp);
          string s;
          int i=0;
          while (iss >> s){
              a[i] = s;
              i++;
          }
          p.nId = a[0];
          p.nlat = a[1];
          p.nlon = a[2];
          nodes.push_back(p);
      }


      //无向图
      char c1, c2;
      int i, p1, p2;
      ENode *node1, *node2;

      //边数与顶点数
      nodeNum = edges.size();
      edgeNum = nodes.size();
      // 初始化"邻接表"的顶点
      for(i=0; i<nodeNum; i++)
      {
          roadNodes[i].data = nodes[i].eId;
          roadNodes[i].firstEdge = NULL;
      }

      // 初始化"邻接表"的边
      for(i=0; i<edgeNum; i++)
      {
          // 读取边的起始顶点和结束顶点
          c1 = edges[i][1];
          c2 = edges[i][2];

          p1 = getPosition(c1);
          p2 = getPosition(c2);
          node1 = new ENode();
          node1->nId = p2;
          // p1所在链表的末尾
          if(roadNodes[p1].firstEdge == NULL)
            roadNodes[p1].firstEdge = node1;
          else
              linkLast(roadNodes[p1].firstEdge, node1);
          node2 = new Node();
          node2->nId = p1;

          if(roadNodes[p2].firstEdge == NULL)
            roadNodes[p2].firstEdge = node2;
          else
              linkLast(roadNodes[p2].firstEdge, node2);
  }
}



int RoadNetwork::getPosition(char c)
{
    int i;
    for(i=0; i<mVexNum; i++)
        if(roadNodes[i].data == c)
            return i;
    return -1;
}
void RoadNetwork::linkLast(ENode *list, ENode *node)//？？？？？？
{
    Edge *p = list;

    while(p->next)
        p = p->next;
        p->next = node;
}
