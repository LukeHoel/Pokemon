#ifndef move_h
#define move_h
#include "../Config/Config.h"
#include "../Helper.h"
#include <initializer_list>
#include <string>
const std::string moveNameKey = "name";
const std::string moveAccuracyKey = "accuracy";
const std::string movePowerKey = "power";
const std::string moveCategoryKey = "category";
std::initializer_list<std::string> moveRequiredKeys = {
    moveNameKey, moveAccuracyKey, movePowerKey, moveCategoryKey};

enum MoveCategory { physical, special, status };
// A pokemon's move
struct Move {
  std::string name;
  int accuracy;
  int power;
  MoveCategory category;
  Move(Config config) {
    if(!config.sectionComplete(moveRequiredKeys)){
      throw std::invalid_argument("Invalid move configuration");
    }
    name = config[moveNameKey];
    accuracy = std::stoi(config[moveAccuracyKey]);
    power = std::stoi(config[movePowerKey]);
    // Turn into enum for easier use later
    std::string lowerCategory = stringToLower(config[moveCategoryKey]);
    if (lowerCategory == "physical") {
      category = physical;
    } else if (lowerCategory == "special") {
      category = special;
    } else if(lowerCategory == "status"){
      category = status;
    }else{
      throw std::invalid_argument("Expected either 'physical', 'special', or 'status' for move category");
    }
  }
};
#endif