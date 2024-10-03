#include "Pasta.h"

// default constructor
Pasta::Pasta() : FoodItem(), pastaSauce("N/A") {}

// constructor without ingredients
Pasta::Pasta(std::string name, double price, int size, std::string pastaSauce)
    : FoodItem(name, price, size), pastaSauce(pastaSauce) {}

// constructor with ingredients
Pasta::Pasta(std::string name, double price, int size, std::string pastaSauce,
             std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients), pastaSauce(pastaSauce) {}

// getter functions
std::string Pasta::get_pastaSauce() { return pastaSauce; }

// setter functions
void Pasta::set_pastaSauce(std::string pastaSauce) {
  this->pastaSauce = pastaSauce;
}

// deconstructor
Pasta::~Pasta(){}