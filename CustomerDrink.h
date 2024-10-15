#ifndef CUSTOMER_DRINKS_H
#define CUSTOMER_DRINKS_H

#include "CustomerFoodDrink.h"
#include "CustomerLogin.h"

class CustomerDrink : public CustomerLogin {
 private:
  int state_drink;
public:
  // runs the portal
  void run(int& state_customer);

  // get the value of state_drink (0 or 1)
  int get_state_drink();

  // default constructor/destructor
  CustomerDrink();
  ~CustomerDrink();
};

#endif