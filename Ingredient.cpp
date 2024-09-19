#include "Ingredient.h"

Ingredient::Ingredient(std::string name, double price) : name(name), price(price) {}

Ingredient::Ingredient() : name("NoName"), price(99999.99) {}

std::string Ingredient::get_name() {
  return name;
}

double Ingredient::get_price() {
  return price;
}

void Ingredient::set_name(std::string name) {
  this->name = name;
}

void Ingredient::set_price(double price) {
  this->price = price;
}