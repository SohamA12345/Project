#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "CustomerFoodDrink.h"
#include "CustomerLogin.h"

class Checkout : public CustomerFoodDrink, public CustomerLogin
{
private:
  int state_checkout;
public:
  void run(int& state);
  int get_state_checkout();
  Checkout();
  ~Checkout();
};

#endif