#include "Pasta.h"

// default constructor
Pasta::Pasta() : FoodItem(), pasta_type("N/A"), pasta_sauce("N/A") {}

// constructor without ingredients
Pasta::Pasta(std::string name, double price, int size, std::string pasta_type, std::string pasta_sauce)
    : FoodItem(name, price, size), pasta_type(pasta_type), pasta_sauce(pasta_sauce) {}

// constructor with ingredients
Pasta::Pasta(std::string name, double price, int size, std::string pasta_type, std::string pasta_sauce,
             std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients), pasta_type(pasta_type), pasta_sauce(pasta_sauce) {}

// getter functions
std::string Pasta::get_pasta_type() { return this->pasta_type; }

std::string Pasta::get_pasta_sauce() { return this->pasta_sauce; }

// setter functions
void Pasta::set_pasta_type(std::string pasta_type) {
  this->pasta_type = pasta_type;
}

void Pasta::set_pasta_sauce(std::string pasta_sauce) {
  this->pasta_sauce = pasta_sauce;
}

// deconstructor
Pasta::~Pasta(){}