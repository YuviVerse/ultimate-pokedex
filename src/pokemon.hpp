#ifndef POKEMON_HPP
#define POKEMON_HPP

namespace Pokedex {

class Pokemon {
private:
    char* name;
    char* type;
    int level;
    
public:
    // Constructors
    Pokemon();
    Pokemon(const char* name, const char* type, int level);

    // Destructor
    ~Pokemon();

    // Accessor methods
    const char* getName() const;
    const char* getType() const;
    int getLevel() const;

    // Mutator methods
    void setName(const char* name);
    void setType(const char* type);
    void setLevel(int level);

    // Friend function
    friend bool compareLevel(const Pokemon& p1, const Pokemon& p2);

    // Overloaded function
    void display() const;
    void display(bool detailed) const;

    // Inline function
    inline bool isHigherLevel(const Pokemon& other) const {
        return level > other.level;
    }

    // Additional functionality
    bool isType(const char* type) const;
    void levelUp(int amount);
};

} // namespace Pokedex

#endif
