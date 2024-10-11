#include "AddToCart.h"

void AddToCart::run(int& state_categories, Pasta& obj) {
  cart.push_back(obj);
  state_categories = 1;
}

void AddToCart::run(int& state_categories, Noodle& obj) {
  cart.push_back(obj);
  state_categories = 1;
}

void AddToCart::run(int& state_categories, Rice& obj) {
  cart.push_back(obj);
  state_categories = 1;
}

void AddToCart::run(int& state_categories, Chips& obj) {
  cart.push_back(obj);
  state_categories = 1;
}

void AddToCart::run(int& state_categories, Pizza& obj) {
  cart.push_back(obj);
  state_categories = 1;
}

void AddToCart::run(int& state_categories, Burger& obj) {
  cart.push_back(obj);
  state_categories = 1;
}

int AddToCart::get_state_checkout() {return this->state_checkout;}

vector<FoodItem> AddToCart::get_cart() {
  return this->cart;
}

AddToCart::AddToCart() {}
AddToCart::~AddToCart() {}