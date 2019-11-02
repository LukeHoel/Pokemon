#ifndef config_h
#define config_h
#include "../Helper.h"
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
class Config {
  std::unordered_map<std::string, std::string> map;
  void addToMap(std::string key, std::string value) {
    if (!key.empty() && !value.empty()) {
      std::string keyName = stringToLower(stringTrim(key));
      map[keyName] = stringTrim(value);
      keys.push_back(keyName);
    }
  }
public:
  std::vector<std::string> keys;
  // Go through each line and extract out a config object
  // It uses the first equals sign in the line to switch from key mode to value
  // mode. Values can have equals signs in them, while keys cannot
  Config(std::string fileName) {
    std::ifstream ifs(fileName);
    // Don't skip whitespace
    ifs >> std::noskipws;
    char current;
    bool foundEquals = false;
    std::string key, value;
    while (ifs >> current) {
      if (current == '\n') {
        // Save the config item
        if (foundEquals) {
          addToMap(key, value);
        }
        key = value = "";
        foundEquals = false;
      } else if (current == '=' && !foundEquals) {
        foundEquals = true;
      } // Switch modes to record value instead of key
      else {
        (foundEquals ? value : key) += current;
      } // Add to either key or value
    }
    // Save the last config item
    if (foundEquals && !key.empty() && !value.empty()) {
      addToMap(key, value);
    }
    ifs.close();
  }
  std::string &operator[](const std::string &key) { return map[stringToLower(key)]; }
};
#endif