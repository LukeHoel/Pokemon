#ifndef helper_h
#define helper_h
#include <algorithm>
#include <cctype>
#include <locale>
#include <string>

// https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case#313990
std::string stringToLower(std::string original) {
  std::string ret(original);
  std::transform(ret.begin(), ret.end(), ret.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return ret;
}

// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
static inline std::string &stringLTrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  [](int ch) { return !std::isspace(ch); }));
  return s;
}

static inline std::string &stringRTrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](int ch) { return !std::isspace(ch); })
              .base(),
          s.end());
  return s;
}
static inline std::string &stringTrim(std::string &s) {
  stringLTrim(s);
  stringRTrim(s);
  return s;
}
#endif