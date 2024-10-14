#ifndef CUSTOMER_FOOD_DRINK_H
#define CUSTOMER_FOOD_DRINK_H

#include "CustomerLogin.h"
#include "FoodItem.h"

class CustomerFoodDrink {
 private:
  int state_customer = 0;

<<<<<<< HEAD
 protected:
  static vector<FoodItem> cart;

 public:
=======
protected:
  // cart which has a array of items
  static vector<FoodItem> cart;

public:
  // runs the portal
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46
  void run(int& state_customer_login);

  // acquires the state of state_customer (0 or 1)
  int get_state_customer();

  // default constructor/destructor
  CustomerFoodDrink();
  ~CustomerFoodDrink();
};

#endif