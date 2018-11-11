/*
 * \file geo_table.h
 * \desc The geometry table, such as point table/polyline table.
 */
#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace mod {

template <int Dimension>
struct GeoPoint {
  double data[Dimension];
  std::vector<std::string> attrs;
};

template <int Dimension>
struct GeoObject {
  std::vector<GeoPoint<Dimension>> data;
  std::vector<std::string> attrs;
};

enum class GeoType {
  kGeoPoint = 0,
  kGeoPolyline,
};

template <int Dimension>
struct GeoObjectTable {
  GeoType geo_type;
  std::vector<GeoObject> geo_objs;
  std::unordered_map<std::string, int> attr_invert_index;
};

}  // namespace mod
