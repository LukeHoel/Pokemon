#ifndef config_h
#define config_h
#include "../Helper.h"
#include <fstream>
#include <initializer_list>
#include <string>
#include <unordered_map>
#include <vector>
class Config {
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      sections;
  void addToMap(std::string section, std::string key, std::string value) {
    if (!section.empty() && !key.empty() && !value.empty()) {
      std::string keyName = stringToLower(stringTrim(key));
      sections[section][keyName] = stringTrim(value);
    }
  }

public:
  Config() {}
  // Go through each line and extract out a config object
  // It uses the first equals sign in the line to switch from key mode to value
  // mode. Values can have equals signs in them, while keys cannot
  Config(std::string fileName) {
    std::ifstream ifs(fileName);
    // Don't skip whitespace
    ifs >> std::noskipws;
    std::string section = "global";
    char current;
    bool foundEquals = false;
    std::string key, value;
    // Check for changing section
    bool foundSectionHeadStart = false;
    bool foundSectionHeadEnd = false;
    std::string sectionCandidate = "";
    while (ifs >> current) {
      if (current == '\n') {
        // Save the config item
        if (foundEquals) {
          addToMap(section, key, value);
        } else if (foundSectionHeadStart && foundSectionHeadEnd &&
                   !sectionCandidate.empty()) {
          section = sectionCandidate;
        }
        // Reset temp variables
        key = value = "";
        foundEquals = false;
        foundSectionHeadStart = false;
        foundSectionHeadEnd = false;
      } else {
        // Handle [section] splitting
        if (foundSectionHeadStart) {
          // Once you have found the end of the section, do nothing until the
          // newline
          if (!foundSectionHeadEnd) {
            if (current == ']') {
              foundSectionHeadEnd = true;
            } else {
              sectionCandidate += current;
            }
          }
        } else {
          // Start recording section header name
          if (current == '[') {
            foundSectionHeadStart = true;
            sectionCandidate = "";
          } else if (current == '=' && !foundEquals) {
            foundEquals = true;
          } // Switch modes to record value instead of key
          else {
            (foundEquals ? value : key) += current;
          } // Add to either key or value
        }
      }
    }
    // Save the last config item
    if (foundEquals && !key.empty() && !value.empty()) {
      addToMap(section, key, value);
    }
    ifs.close();
  }
  // Get the section as a config object in of itself
  Config subConfig(std::string section = "global") {
    Config ret;
    for (const std::string &key : keys(section)) {
      ret.addToMap("global", key, this->section(section)[key]);
    }
    return ret;
  }
  // Get reference to specific section
  std::unordered_map<std::string, std::string>
  section(std::string section = "global") {
    return sections[stringToLower(section)];
  }
  // Only checks in global
  std::string &operator[](const std::string &key) {
    return sections["global"][key];
  }
  // Get the keys from a section
  std::vector<std::string> keys(std::string section = "global") {
    std::vector<std::string> ret;
    for (auto keyValue : this->section(section)) {
      ret.push_back(keyValue.first);
    }
    return ret;
  }
  // Get the values from a section
  std::vector<std::string> values(std::string section = "global") {
    std::vector<std::string> ret;
    for (auto keyValue : this->section(section)) {
      ret.push_back(keyValue.second);
    }
    return ret;
  }
  // Check if contents of section (global by default, contains the required
  // keys)
  bool sectionComplete(std::initializer_list<std::string> &requiredKeys,
                       std::string section = "global") {
    // Make sure that the config object has the required keys
    for (const std::string &key : requiredKeys) {
      if (this->section(section).find(key) == this->section(section).end()) {
        return false;
      }
    }
    return true;
  }

  // Print out a given sections contents
  void print(std::string section = "global") {
    std::cout << "Printing keys=values for " << section << std::endl;
    for (std::string key : keys(section)) {
      std::cout << key << "=" << this->section(section)[key] << std::endl;
    }
  }
};
#endif