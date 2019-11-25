#ifndef TRAINER_H
#define TRAINER_H
#include "Team.h"
#include <string>
std::string trainerNameKey = "name";
std::initializer_list<std::string> trainerRequiredKeys = {trainerNameKey};
struct Trainer {
  std::string name;
  Team team;
  Trainer(){}
  Trainer(Config config) {
    if (config.sectionComplete(trainerRequiredKeys)) {
      name = config[trainerNameKey];
      team = Team(config);
    } else {
      throw new std::invalid_argument("Invalid trainer config");
    }
  }
};
Trainer playerTrainer;
#endif