#ifndef config_h
#define config_h
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
struct Config{
  std::unordered_map<std::string, std::string> map;
  std::vector<std::string> keys;
  // Go through each line and extract out a config object
  // It uses the first equals sign in the line to switch from key mode to value mode.
  // Values can have equals signs in them, while keys cannot
  Config(std::string fileName){
    std::ifstream ifs(fileName);
    // Don't skip whitespace
    ifs >> std::noskipws;
    char current;
    bool foundEquals = false;
    std::string key, value;
    while(ifs >> current){
      if(current == '\n') { 
        // Save the config item
        if(foundEquals && !key.empty() && !value.empty()){
          map[key] = value;
          keys.push_back(key);
        }
        key = value = "";
        foundEquals = false;
      }
      else if(current == '=' && !foundEquals){ foundEquals = true; } // Switch modes to record value instead of key
      else { (foundEquals ? value : key) += current; } // Add to either key or value
    }
    // Save the last config item
    if(foundEquals && !key.empty() && !value.empty()){
      map[key] = value;
      keys.push_back(key);
    }
    ifs.close();
  }
};
#endif