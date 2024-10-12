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
  void add_to_cart(FoodItem obj);

  int get_state_checkout();
  vector<FoodItem*> get_cart();

  AddToCart();
  ~AddToCart();
};

#endif