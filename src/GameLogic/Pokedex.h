#ifndef pokedex_h
#define pokedex_h
#include <initializer_list>
#include <unordered_map>
#include <string>
#include "../Config/Config.h"
struct Pokemon;
struct Pokedex{
  Pokedex(std::initializer_list<std::string> names){
    Config config("config/pokemon/bulbasaur.pkm");
    std:: cout << config.map["test"];
    std:: cout << config.map["test2"];
    std:: cout << config.map["test 3"];
    for(std::string name: names){
      std::cout << name;
    }
  }
  std::unordered_map<std::string, Pokemon*> availablePokemon;
};
Pokedex pokedex({"Bulbasaur", "Charmander"});
#endif