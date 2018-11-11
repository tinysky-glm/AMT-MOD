/*
 * \file txt2shp_main.cc
 * \desc The txt2shp tool
 */
#include "mod/utils/txt2shp.h"

#include <iostream>

namespace mod {

void Convert(const char* infile, const char* outfile, const char* delim, int is_point) {
  Txt2ShpConverter t2sc;
  if (is_point) {
    t2sc.ConvertPoint(infile, outfile, delim);
  } else {
    t2sc.ConvertEdge(infile, outfile, delim);
  }
}

}  // namespace mod

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cerr << "Usage: " << argv[0] << " infile outfile delim is_point(0/1)" << std::endl;
    return 1;
  }
  mod::Convert(argv[1], argv[2], argv[3], std::stoi(argv[4]));
  return 0;
}
