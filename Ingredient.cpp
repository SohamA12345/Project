#include "Ingredient.h"
#include <string>

// default constructor
Ingredient::Ingredient() : name("N/A"), price(0.00) {}

// constructor
Ingredient::Ingredient(std::string name, double price) : name(name), price(price) {}

// getter functions
std::string Ingredient::get_name() {
  return name;
}

double Ingredient::get_price() {
  return price;
}

//setter functions
void Ingredient::set_name(std::string name) {
  this->name = name;
}

void Ingredient::set_price(double price) {
  this->price = price;
}

bool Ingredient::operator==(Ingredient& name) {
  return this->name == name.name;
}

// deconstructor
Ingredient::~Ingredient() {}