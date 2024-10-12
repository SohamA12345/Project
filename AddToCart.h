#ifndef ADD_TO_CART_H
#define ADD_TO_CART_H

#include "Pasta.h"
#include "Pizza.h"
#include "Noodle.h"
#include "Rice.h"
#include "Chips.h"
#include "Burger.h"
#include "FoodItem.h"

class AddToCart
{
private:
  int state_checkout;
  Pasta empty;
  vector<FoodItem*> cart;
public:
  void run(int& state_categories, Pasta& obj);
  void run(int& state_categories, Noodle& obj);
  void run(int& state_categories, Rice& obj);
  void run(int& state_categories, Chips& obj);
  void run(int& state_categories, Pizza& obj);
  void run(int& state_categories, Burger& obj);

  int get_state_checkout();
  vector<FoodItem*> get_cart();

  AddToCart();
  ~AddToCart();
};

#endif