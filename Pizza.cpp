#include "Pizza.h"

// default constructor
Pizza::Pizza() : FoodItem(), pizza_sauce("N/A"), pizza_cheese("N/A") {}

// constructor without ingredients
Pizza::Pizza(std::string name, double price, int size, std::string pizza_sauce, std::string pizza_cheese)
    : FoodItem(name, price, size), pizza_sauce(pizza_sauce), pizza_cheese(pizza_cheese) {}

// constructor with ingredients
Pizza::Pizza(std::string name, double price, int size, std::string pizza_sauce, std::string pizza_cheese,
             std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients), pizza_sauce(pizza_sauce), pizza_cheese(pizza_cheese) {}

// getter functions
std::string Pizza::get_pizza_sauce() { return pizza_sauce; }

std::string Pizza::get_pizza_cheese() { return pizza_cheese; }

// setter functions
void Pizza::set_pizza_sauce(std::string pizza_sauce) {
  this->pizza_sauce = pizza_sauce;
}

void Pizza::set_pizza_cheese(std::string pizza_cheese) {
  this->pizza_cheese = pizza_cheese;
}

// deconstructor
Pizza::~Pizza(){}