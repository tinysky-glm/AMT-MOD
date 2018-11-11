/*
 * \file txt2shp_main.cc
 * \desc The txt2shp tool
 */
#include "mod/utils/txt2shp.h"

#include <iostream>

namespace mod {

void Convert(const char* infile, const char* outfile) {
  Txt2ShpConverter t2sc;
  t2sc.ConvertPoint(infile, outfile);
}

}  // namespace mod

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " infile outfile" << std::endl;
    return 1;
  }
  mod::Convert(argv[1], argv[2]);
  return 0;
}
