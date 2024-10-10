#include "Chips.h"

// default constructor
Chips::Chips() : FoodItem(), chips_cut("N/A"), chips_seasoning("N/A") {}

// constructor without ingredient list
Chips::Chips(std::string name, double price, int size, std::string chips_cut,
               std::string chips_seasoning)
    : FoodItem(name, price, size),
      chips_cut(chips_cut),
      chips_seasoning(chips_seasoning) {}

// constructor with ingredient list
Chips::Chips(std::string name, double price, int size, std::string chips_cut,
               std::string chips_seasoning, std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients),
      chips_cut(chips_cut),
      chips_seasoning(chips_seasoning) {}

// getter functions
std::string Chips::get_chips_cut() { return this->chips_cut; }
std::string Chips::get_chips_seasoning() { return this->chips_seasoning; }

// setter functions
void Chips::set_chips_cut(std::string chips_cut) {
  this->chips_cut = chips_cut;
}
void Chips::set_chips_seasoning(std::string chips_seasoning) {
  this->chips_seasoning = chips_seasoning;
}

// deconstructor
Chips::~Chips() {}