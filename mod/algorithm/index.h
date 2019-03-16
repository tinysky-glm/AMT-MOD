#pragma once

#include "mod/storage/point.h"
#include "mod/storage/road_network.h"

#include <vector>
namespace mod{
    class Index{
    public:
	//获取交叉点
	explicit Index(const std::vector<Point>& points);
	// 寻找以交叉口为圆心，给定半径内的轨迹点
	std::vector<Point> Search(const Point& point, float radis);
	//匹配距离交叉点最近的轨迹点
        Point getNearestEdge(const Point& point);
    };
}

