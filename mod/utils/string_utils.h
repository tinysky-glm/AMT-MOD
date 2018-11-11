/*
 * \file string_utils.h
 * \desc The string utilitys
 */
#include <string.h>

#include <string>
#include <vector>

namespace mod {

inline std::vector<std::string> Split(const std::string& raw_str, const std::string& delim) {
  std::vector<std::string> splits;
  const char* s1 = raw_str.c_str();
  const char* s2 = delim.c_str();
  while (s1 != nullptr) {
    const char* pos = strstr(s1, s2);
    if (pos == nullptr) {
      splits.push_back(s1);
      break;
    }
    splits.push_back(std::string(s1, pos - s1));
    s1 = pos + delim.length();
  }
  return splits;
}

}  // namespace mode
