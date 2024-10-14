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

public:
  // add an object of class FoodItem into the cart
  void add_to_cart(FoodItem obj);

  // get the state of checkout
  int get_state_checkout();

  // returns an array of pointers to FoodItems 
  vector<FoodItem*> get_cart();

  AddToCart();
  ~AddToCart();
};

#endif