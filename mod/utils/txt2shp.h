/*
 * \file txt2shp.h
 * \desc The text to shapefile convertor
 */
#include <string>

#include "shapelib/shapelib/shapefil.h"
#include "mod/utils/status.h"

namespace mod {

// The text to shapefile conveter
class Txt2ShpConverter {
 public:
  Status ConvertPoint(const char* infile, const char* outfile);
  Status ConvertEdge(const char* infile, const char* outfile);
};

}  // namespace mod
