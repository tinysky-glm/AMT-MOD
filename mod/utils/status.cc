/*
 * \file status.cc
 * \desc The status in mod system
 */
#include "./status.h"

namespace mod {

std::string GetStatusString(const Status& status) {
  switch (status) {
    case Status::kSuccess:
      return "Success";
    case Status::kOpenFileFail:
      return "OpenFileFail";
    case Status::kFail:
    default:
      return "Fail";
  }
}

}  // namespace mod

