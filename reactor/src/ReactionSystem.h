#include <string> // use the string capabilities from the standard library
#include <vector>
#include <set>

#include "Species.h"
#include "Reaction.h"

#ifndef ONCE_REACTIONSYSTEM_H
#define ONCE_REACTIONSYSTEM_H

class ReactionSystem // A "class" is a user defined type with built-in functions
{   
public:
  ReactionSystem(); // Declare constructor function.
  void AddReaction(const Reaction& reaction);
  const std::vector<const Reaction *> & GetReactions() {return reactions;}
  const std::vector<const double> & GetRates() const; // Given the current species concentrations, return the rates of change
  const std::vector< double> GetConcentrations() const ; // return array of species concentrations
  void SetConcentrations(const std::vector<double> & );
  void AddSpecies(Species * species);
  std::vector<Species *> & GetSpecies() { return species;}
private:
  void EnsureAllSpeciesPresent(const Reaction& reaction);
  bool SpeciesAlreadyPresent(Species * new_species);
  std::vector< const Reaction * > reactions;
  std::vector< Species * > species;
  std::set<Species *> species_set; // C++ has no ordered set without using boost: use both a vector and a set.
};

#endif //ONCE_REACTIONSYSTEM_H
