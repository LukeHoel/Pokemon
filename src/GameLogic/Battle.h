#ifndef battle_h
#define battle_h
#include "Trainer.h"
#include <queue>
struct BattleStep {
  enum BattleStepType { USEMOVE, USEITEM, SWITCHPOKEMON, RUN };
  Trainer *source;
  BattleStepType type;
  Move *move;
  BattleStep(Trainer *source, BattleStepType type)
      : source(source), type(type) {}
  BattleStep(Trainer *source, BattleStepType type, Move *move)
      : source(source), type(type), move(move) {}
};
struct Battle {
  // In battle team state
  Trainer *trainer1;
  Trainer *trainer2;
  int trainer1CurrentPokemon = 0;
  int trainer2CurrentPokemon = 0;
  // battle queue and if the battle is over
  std::queue<BattleStep> battleStepQueue;
  bool over = false;
  Trainer *winner;
  Battle(Trainer *trainer1, Trainer *trainer2)
      : trainer1(trainer1), trainer2(trainer2) {}
  void step() {
    while (!battleStepQueue.empty()) {
      BattleStep currentStep = battleStepQueue.front();
      // Setup the effecting and affected team and current pokemon
      bool isSourcetrainer1 = currentStep.source == trainer1;
      Trainer *effectingTrainer = isSourcetrainer1 ? trainer1 : trainer2;
      Trainer *affectedTrainer = isSourcetrainer1 ? trainer2 : trainer1;
      Pokemon *effectingCurrentPokemon =
          isSourcetrainer1 ? &trainer1->team.members[trainer1CurrentPokemon]
                           : &trainer2->team.members[trainer2CurrentPokemon];
      Pokemon *affectedCurrentPokemon =
          isSourcetrainer1 ? &trainer2->team.members[trainer2CurrentPokemon]
                           : &trainer1->team.members[trainer1CurrentPokemon];
      switch (currentStep.type) {
      case (BattleStep::USEMOVE):
        effectingCurrentPokemon->attack(*affectedCurrentPokemon,
                                        *currentStep.move);
        break;
      case (BattleStep::RUN):
        over = true;
        break;
      }
      // check if the battle should end because all pokemon are fainted
      // Only checks for first one at the moment
      if (affectedCurrentPokemon->HP <= 0) {
        winner = effectingTrainer;
        over = true;
        break;
      }
      battleStepQueue.pop();
    }
  }
};
#endif