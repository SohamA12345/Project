#include "Pizza.h"

// default constructor
Pizza::Pizza() : FoodItem(), pizzaSauce("N/A"), pizzaBase("N/A") {}

// constructor without ingredients
Pizza::Pizza(std::string name, double price, int size, std::string pizzaSauce, std::string pizzaBase)
    : FoodItem(name, price, size), pizzaSauce(pizzaSauce), pizzaBase(pizzaBase) {}

// constructor with ingredients
Pizza::Pizza(std::string name, double price, int size, std::string pizzaSauce, std::string pizzaBase,
             std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients), pizzaSauce(pizzaSauce), pizzaBase(pizzaBase) {}

// getter functions
std::string Pizza::get_pizzaSauce() { return pizzaSauce; }

std::string Pizza::get_pizzaBase() { return pizzaBase; }

// setter functions
void Pizza::set_pizzaSauce(std::string pizzaSauce) {
  this->pizzaSauce = pizzaSauce;
}

void Pizza::set_pizzaBase(std::string pizzaBase) {
  this->pizzaBase = pizzaBase;
}

// deconstructor
Pizza::~Pizza(){}