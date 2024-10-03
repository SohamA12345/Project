#ifndef CHECKOUT_H
#define CHECKOUT_H

class Checkout
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