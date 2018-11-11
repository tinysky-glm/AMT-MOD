/*
 * \file status.h
 * \desc The status in mod system
 */
#include <string>

namespace mod {

enum class Status {
  kSuccess = 0,
  kOpenFileFail,
  kFail,
};

std::string GetStatusString(const Status& status);

}  // namespace mod
