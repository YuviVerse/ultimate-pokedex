#include "../src/linkedlist.hpp"
#include "../src/utility.hpp"
#include <iostream>
#include <cassert>

using namespace Pokedex;

void testAddPokemon() {
    LinkedList pokedex;
    Pokemon pikachu("Pikachu", "Electric", 25);
    pokedex.addPokemon(pikachu);
    assert(pokedex.searchPokemon("Pikachu") != nullptr);
    std::cout << "Test Add Pokemon: Passed" << std::endl;
}

void testRemovePokemon() {
    LinkedList pokedex;
    Pokemon pikachu("Pikachu", "Electric", 25);
    pokedex.addPokemon(pikachu);
    pokedex.removePokemon("Pikachu");
    assert(pokedex.searchPokemon("Pikachu") == nullptr);
    std::cout << "Test Remove Pokemon: Passed" << std::endl;
}

void testSortPokemonsByLevel() {
    LinkedList pokedex;
    Pokemon pikachu("Pikachu", "Electric", 25);
    Pokemon charmander("Charmander", "Fire", 15);
    pokedex.addPokemon(pikachu);
    pokedex.addPokemon(charmander);
    pokedex.sortPokemonsByLevel();
    Node* head = pokedex.searchPokemon("Charmander");
    assert(head != nullptr && head->data.getLevel() == 15);
    std::cout << "Test Sort Pokemons By Level: Passed" << std::endl;
}

void testDisplayByType() {
    LinkedList pokedex;
    Pokemon pikachu("Pikachu", "Electric", 25);
    Pokemon charmander("Charmander", "Fire", 15);
    pokedex.addPokemon(pikachu);
    pokedex.addPokemon(charmander);
    pokedex.displayByType("Electric");
    std::cout << "Test Display By Type: Passed" << std::endl;
}

void testReadFromFile() {
    LinkedList pokedex;
    Utility::readPokemonFromFile("../pokemon_list.txt", pokedex);
    assert(pokedex.searchPokemon("Pikachu") != nullptr);
    std::cout << "Test Read From File: Passed" << std::endl;
}

int main() {
    testAddPokemon();
    testRemovePokemon();
    testSortPokemonsByLevel();
    testDisplayByType();
    testReadFromFile();
    return 0;
}
