/*!
 * \file point.h
 * \brief The point.
 */
#pragma once

#include "mod/common/common_defines.h"

namespace mod {

struct Point {
  Point() { }
  Point(mod_int_t index, mod_float_t lon, mod_float_t lat)
      : index(index), lon(lon), lat(lat) {
  }
  mod_int_t index;
  mod_float_t lon;
  mod_float_t lat;
};

}  // namespace mod
