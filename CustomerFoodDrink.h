#ifndef CUSTOMER_FOOD_DRINK_H
#define CUSTOMER_FOOD_DRINK_H

#include "CustomerLogin.h"
#include "FoodItem.h"

class CustomerFoodDrink {
 private:
  int state_customer = 0;

 protected:
  static vector<FoodItem> cart;

 public:
  void run(int& state_customer_login);
  int get_state_customer();
  CustomerFoodDrink();
  ~CustomerFoodDrink();
};

#endif