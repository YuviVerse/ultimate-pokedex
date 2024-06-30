#include "linkedlist.hpp"
#include "utility.hpp"
#include <iostream>

using namespace Pokedex;

void displaySubMenu(LinkedList& pokedex);

int main() {
    LinkedList pokedex;
    Utility::readPokemonFromFile("pokemon_list.txt", pokedex);

    std::cout << "Pokedex Loaded:\n";
    pokedex.displayAll();

    int choice;
    do {
        std::cout << "\nPokedex Menu:\n";
        std::cout << "1. View All Pokemon\n";
        std::cout << "2. Add New Pokemon\n";
        std::cout << "3. Search Pokemon\n";
        std::cout << "4. Remove Pokemon\n";
        std::cout << "5. Sort Pokemon by Level\n";
        std::cout << "6. Display Pokemon by Type\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displaySubMenu(pokedex);
                break;
            case 2: {
                char name[50], type[50];
                int level;
                std::cout << "Enter Pokemon Name: ";
                std::cin >> name;
                std::cout << "Enter Pokemon Type: ";
                std::cin >> type;
                std::cout << "Enter Pokemon Level: ";
                std::cin >> level;
                Pokemon newPokemon(name, type, level);
                pokedex.addPokemon(newPokemon);
                break;
            }
            case 3: {
                char name[50];
                std::cout << "Enter Pokemon Name to Search: ";
                std::cin >> name;
                Node* found = pokedex.searchPokemon(name);
                if (found) {
                    found->data.display();
                } else {
                    std::cout << "Pokemon not found.\n";
                }
                break;
            }
            case 4: {
                char name[50];
                std::cout << "Enter Pokemon Name to Remove: ";
                std::cin >> name;
                pokedex.removePokemon(name);
                break;
            }
            case 5:
                pokedex.sortPokemonsByLevel();
                break;
            case 6: {
                char type[50];
                std::cout << "Enter Pokemon Type to Display: ";
                std::cin >> type;
                pokedex.displayByType(type);
                break;
            }
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

void displaySubMenu(LinkedList& pokedex) {
    int displayChoice;
    std::cout << "\nDisplay Menu:\n";
    std::cout << "1. Regular Display\n";
    std::cout << "2. Display by Attribute\n";
    std::cout << "Enter your choice: ";
    std::cin >> displayChoice;

    if (displayChoice == 1) {
        pokedex.displayAll(NAME); // Regular display
    } else if (displayChoice == 2) {
        int attributeChoice;
        std::cout << "\nDisplay by Attribute:\n";
        std::cout << "1. Name\n";
        std::cout << "2. Type\n";
        std::cout << "3. Level\n";
        std::cout << "Enter your choice: ";
        std::cin >> attributeChoice;

        switch (attributeChoice) {
            case 1:
                pokedex.displayAll(NAME);
                break;
            case 2:
                pokedex.displayAll(TYPE);
                break;
            case 3:
                pokedex.displayAll(LEVEL);
                break;
            default:
                std::cout << "Invalid choice! Displaying regular view.\n";
                pokedex.displayAll(NAME);
                break;
        }
    } else {
        std::cout << "Invalid choice! Displaying regular view.\n";
        pokedex.displayAll(NAME);
    }
}