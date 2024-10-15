#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "CustomerFoodDrink.h"
#include "CustomerLogin.h"

class Checkout : public CustomerFoodDrink, public CustomerLogin {
 private:
  int state_checkout;
public:
  // runs the portal
  void run(int& state);

  // gets the state of checkout (0 or 1)
  int get_state_checkout();

  // default constructor/destructor
  Checkout();
  ~Checkout();
};

#endif