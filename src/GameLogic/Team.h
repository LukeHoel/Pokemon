#ifndef TEAM_H
#define TEAM_H
#include "../Config/Config.h"
#include "Pokemon.h"
#include <vector>

struct Team {
  std::vector<Pokemon> members;
  bool isWild = false;
  Team() {}
  // Go through the team members and see how many have been defined
  Team(Config config) {
    for (int i = 0; i < 6; i++) {
      auto index = std::to_string(i);
      if (config.sectionComplete(pokemonRequiredKeys, index)) {
        members.push_back(Pokemon(config.subConfig(index)));
      }
    }
    if (members.empty()) {
      throw std::invalid_argument("No valid pokemon on the team");
    }
  }
};
#endif