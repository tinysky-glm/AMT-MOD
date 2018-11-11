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
  // The format of Text Point file
  // [entity number] delim [latitude] delim [longtitude]
  Status ConvertPoint(const char* infile, const char* outfile, const char* delim);

  // The format of Text Edge file
  // [entity number] delim [name] delim [type] delim [len] delim [latitude]
  // delim [logtitude] ....
  Status ConvertEdge(const char* infile, const char* outfile, const char* delim);
};

}  // namespace mod
