#ifndef CUSTOMER_FOOD_DRINK_H
#define CUSTOMER_FOOD_DRINK_H

#include "CustomerLogin.h"
#include "FoodItem.h"
#include "Drink.h"

class CustomerFoodDrink {
 private:
  int state_customer = 0;

 public:
  // runs the portal
  void run(int& state_customer_login);

  // The cart that stores all the food.
  static vector<FoodItem> cart;
  static vector<Drink> cart_drink;

  // acquires the state of state_customer (0 or 1)
  int get_state_customer();

  // default constructor/destructor
  CustomerFoodDrink();
  ~CustomerFoodDrink();
};

#endif