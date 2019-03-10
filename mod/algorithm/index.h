#pragma once

#include "mod/storage/point.h"
#include "mod/storage/road_network.h"

#include <vector>
namespace mod{
    //获取交叉点
    const std::vector<Point> nodes_ = nodes();
    //边缘
    struct Edge {
    	int  edge_index;
    	int	 start_node_index;
    	int	 end_node_index;
    	int  edge_length;
    };

    //路径应该是边缘的集合??
    std::vector<struct Edge> path_;
    /**
    struct Path {
    	int  path_index;
    	int	 start_path_index;
    	int	 end_path_index;
    };
    */

    //带有时间戳的轨迹点
    struct TrajectoryNode {
    	struct Point point;
    	int	 timestamp;
    };

    //轨迹
    std::vector<struct TrajectoryNode> trajectory_;

    //轨迹片段
    struct SegTrajectory {
    	int  seg_time;//经过时间
    	int	 start_seg_index;
    	int	 end_seg_index;
    	int  seg_length;
    };
    class Index{
    public:
        Index(const std::vector<Point>& points);

        // 外部接口....
        std::vector<int> Search(const Point& point, float radis);
#if 0
        //初始化路径,传一个起点边缘
        void initPath(struct Edge *edge);
        //顶点下标即为索引，建立对应边缘的索引,通过link_list(size_t index)
        int index(std::vector<Point> nodes_);
        //获取带有时间戳的轨迹片段
        struct SegTrajectory getSegTrajectory(int index);
        //获取轨迹片段向量pi到p i+1
        struct SegTrajectory getSegTrajectory(int index);
#endif
    };
}

