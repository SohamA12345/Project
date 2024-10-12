#include "AddToCart.h"

void AddToCart::add_to_cart(FoodItem obj) {
  cart.push_back(&obj);
  cout << cart.size();
  cin.get();
}

vector<FoodItem*> AddToCart::get_cart() {
  return this->cart;
}

AddToCart::AddToCart() {}

AddToCart::~AddToCart() {}