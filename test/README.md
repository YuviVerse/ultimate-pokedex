# Pokedex Project Test Suite

Welcome to the test suite for the Ultimate Pokedex Project! This README will guide you through running the tests for your Pokedex implementation to ensure everything works as expected.

## Test Overview
The test suite includes the following tests:
1. **Test Add Pokemon**: Verifies that a new Pokemon can be added to the Pokedex.
2. **Test Remove Pokemon**: Verifies that a Pokemon can be removed from the Pokedex.
3. **Test Sort Pokemons By Level**: Verifies that the Pokemon in the Pokedex can be sorted by their level.
4. **Test Display By Type**: Verifies that Pokemon can be displayed by their type.

## Getting Started

### Prerequisites
Ensure you have the following:
- A working C++ compiler (e.g., `g++`)
- The project files (main.cpp, pokemon.cpp, linkedlist.cpp, utility.cpp) correctly implemented
- The `pokemon_list.txt` file in the root directory of the project

### Running the Tests

1. **Navigate to the `test` directory**:
    ```sh
    cd /path-to-your-project/ultimate-pokedex/test
    ```

2. **Compile the test file**:
    ```sh
    g++ -o test_pokedex test_main.cpp ../src/main.cpp ../src/pokemon.cpp ../src/linkedlist.cpp ../src/utility.cpp
    ```

3. **Run the test executable**:
    ```sh
    ./test_pokedex
    ```

### Expected Output

When you run the test, you should see the following output:

```plaintext
Pokedex Loaded:
Bulbasaur (Grass), Level: 5
Ivysaur (Grass), Level: 10
...
Pikachu (Electric), Level: 25
Charmander (Fire), Level: 15

Test Add Pokemon: Passed
Test Remove Pokemon: Passed
Test Sort Pokemons By Level: Passed
Electric Pokemon:
Pikachu (Electric), Level: 25
Test Display By Type: Passed
