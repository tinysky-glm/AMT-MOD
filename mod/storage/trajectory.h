/*!
 * \file trajectory.h
 * \brief The trajectory of moving object, such as taxi.
 */
#pragma once

#include <string>
#include <vector>

#include "mod/storage/point.h"

namespace mod {

class Trajectory {
 public:
  Trajectory();
  /*
   * 根据轨迹文件，构建轨迹类.
   */
  explicit Trajectory(const std::string& file);
  
  /*
   * 追加新的点到轨迹里
   */
  void AddPoint(const Point& point);

  /*
   * 返回第index个轨迹点,index取值范围[0, point_num())
   */
  const Point& point(int index) const {
    return points_[index];
  }
  /*
   * 返回所有的轨迹点
   */
  const std::vector<Point>& points() const {
    return points_;
  }
  /*
   * 返回轨迹包含多少个点。
   */
  size_t point_num() const {
    return points_.size();
  }

 protected:
  /*
   * std::vector是C++的Array容器类, 可参考C++ Reference查找用途.
   * http://www.cplusplus.com/reference/
   */
  std::vector<Point> points_;
};

}  // namespace mod
