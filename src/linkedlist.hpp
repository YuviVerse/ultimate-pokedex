#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "pokemon.hpp"

namespace Pokedex {

// Node structure for LinkedList
struct Node {
    Pokemon data;
    Node* next;
};

// LinkedList class to manage the Pokedex
class LinkedList {
private:
    Node* head;
    
public:
    LinkedList();
    ~LinkedList();
    
    void addPokemon(const Pokemon& p);
    void displayAll() const;
    void displayAll(DisplayAttribute attribute) const;
    Node* searchPokemon(const char* name) const;
    void removePokemon(const char* name);
    void sortPokemonsByLevel();
    void displayByType(const char* type) const;
};

} // namespace Pokedex

#endif
