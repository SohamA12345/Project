#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "CustomerFoodDrink.h"
#include "CustomerLogin.h"

class Checkout : public CustomerFoodDrink, public CustomerLogin {
 private:
  int state_checkout;
<<<<<<< HEAD

 public:
=======
public:
  // runs the portal
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46
  void run(int& state);

  // gets the state of checkout (0 or 1)
  int get_state_checkout();

  // default constructor/destructor
  Checkout();
  ~Checkout();
};

#endif