#include "Burger.h"

// default constructor
Burger::Burger() : FoodItem(), burger_bun("N/A"), burger_meat("N/A") {}

// constructor without ingredient list
Burger::Burger(std::string name, double price, int size, std::string burger_bun,
               std::string burger_meat)
    : FoodItem(name, price, size),
      burger_bun(burger_bun),
      burger_meat(burger_meat) {}

// constructor with ingredient list
Burger::Burger(std::string name, double price, int size, std::string burger_bun,
               std::string burger_meat, std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients),
      burger_bun(burger_bun),
      burger_meat(burger_meat) {}

// getter functions
std::string Burger::get_burger_bun() { return this->burger_bun; }
std::string Burger::get_burger_meat() { return this->burger_meat; }

// setter functions
void Burger::set_burger_bun(std::string burger_bun) {
  this->burger_bun = burger_bun;
}
void Burger::set_burger_meat(std::string burger_meat) {
  this->burger_meat = burger_meat;
}

// deconstructor
Burger::~Burger() {}