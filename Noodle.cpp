#include "Noodle.h"

Noodle::Noodle() : FoodItem(), noodle_type("N/A"), noodle_soup("N/A") {}

// constructor without ingredient list
Noodle::Noodle(std::string name, double price, int size,
               std::string noodle_type, std::string noodle_soup)
    : FoodItem(name, price, size),
      noodle_type(noodle_type),
      noodle_soup(noodle_soup) {}

// constructor with ingredient list
Noodle::Noodle(std::string name, double price, int size,
               std::string noodle_type, std::string noodle_soup,
               std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients),
      noodle_type(noodle_type),
      noodle_soup(noodle_soup) {}

// getter functions
std::string Noodle::get_noodle_type() { return this->noodle_type; }
std::string Noodle::get_noodle_soup() { return this->noodle_soup; }

// setter functions
void Noodle::set_noodle_type(std::string noodle_type) {
  this->noodle_type = noodle_type;
}
void Noodle::set_noodle_soup(std::string noodle_soup) {
  this->noodle_soup = noodle_soup;
}

// deconstructor
Noodle::~Noodle() {}