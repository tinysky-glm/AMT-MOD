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

Status Txt2ShpConverter::ConvertPoint(const char* infile, const char* outfile, const char* delim) {
  std::ifstream in(infile, std::ifstream::in);
  if (!in.good()) return Status::kOpenFileFail;
 
  auto shp_handle = SHPCreate(outfile, SHPT_POINT);
  while (!in.eof()) {
    std::string line;
    std::getline(in, line);
    auto splits = Split(line, delim);
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

Status Txt2ShpConverter::ConvertEdge(const char* infile, const char* outfile, const char* delim) {
  std::ifstream in(infile, std::ifstream::in);
  if (!in.good()) return Status::kOpenFileFail;

  auto shp_handle = SHPCreate(outfile, SHPT_ARC);
  auto dbf_handle = DBFCreate(outfile);
  auto name_field_index = DBFAddField(dbf_handle, "name", FTString, 32, 0);
  auto type_field_index = DBFAddField(dbf_handle, "type", FTString, 16, 0);
  auto len_field_index = DBFAddField(dbf_handle, "len", FTDouble, 16, 8);

  std::vector<double> polyline[2];
  while (!in.eof()) {
    std::string line;
    std::getline(in, line);
    auto splits = Split(line, delim);
    if (splits.size() < 6 || splits.size() % 2 != 0) continue;
    auto i = std::stoi(splits[0]);
    auto name = splits[1];
    auto type = splits[2];
    auto len = std::stod(splits[3]);
    polyline[0].clear();
    polyline[1].clear();
    for (auto k = 4; k < splits.size(); k += 2) {
      polyline[0].push_back(std::stod(splits[k]));
      polyline[1].push_back(std::stod(splits[k + 1]));
    }
    auto shp_object = SHPCreateSimpleObject(SHPT_ARC, polyline[0].size(),
                                            polyline[0].data(), polyline[1].data(), nullptr);
    auto ishape = SHPWriteObject(shp_handle, -1, shp_object);
   
    DBFWriteStringAttribute(dbf_handle, ishape, name_field_index, name.c_str());
    DBFWriteStringAttribute(dbf_handle, ishape, type_field_index, type.c_str());
    DBFWriteDoubleAttribute(dbf_handle, ishape, len_field_index, len);  
  }
  SHPClose(shp_handle);
  DBFClose(dbf_handle);
  return Status::kSuccess;
}

}  // namespace mod

