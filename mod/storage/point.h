/*!
 * \file point.h
 * \brief The point.
 */
#pragma once

#include "mod/common/common_defines.h"

namespace mod {

struct Point {
  Point() { }
  Point(mod_float_t lon, mod_float_t lat)
      : lon(lon), lat(lat) {
  }

  mod_float_t lon;
  mod_float_t lat;
};

}  // namespace mod
