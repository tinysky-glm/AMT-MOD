/*
 * \file txt2shp.cc
 * \desc The text to shapefile convertor
 */
#include "mod/utils/txt2shp.h"

#include <fstream>
#include <iostream>

#include "mod/utils/string_utils.h"
#include "shapelib/shapelib/shapefil.h"

namespace mod {

Status Txt2ShpConverter::ConvertPoint(const char* infile, const char* outfile) {
  std::ifstream in(infile, std::ifstream::in);
  if (!in.good()) return Status::kOpenFileFail;
 
  auto shp_handle = SHPCreate(outfile, SHPT_POINT);
  while (!in.eof()) {
    std::string line;
    std::getline(in, line);
    auto splits = Split(line, " ");
    if (splits.size() < 3) continue;
    auto i = std::stoi(splits[0]);
    auto x = std::stod(splits[1]);
    auto y = std::stod(splits[2]);
    auto shp_object = SHPCreateSimpleObject(SHPT_POINT, 1, &x, &y, nullptr);
    SHPWriteObject(shp_handle, -1, shp_object);
  }
  SHPClose(shp_handle);
  return Status::kSuccess;
}

Status Txt2ShpConverter::ConvertEdge(const char* infile, const char* outfile) {
  return Status::kSuccess;
}

}  // namespace mod

