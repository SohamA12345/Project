#ifndef ADD_TO_CART_H
#define ADD_TO_CART_H

class AddToCart
{
private:
  int state_checkout;
public:
  void run(int& state_categories);
  int get_state_checkout();
  AddToCart();
  ~AddToCart();
};

#endif