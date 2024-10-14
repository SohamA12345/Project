#ifndef CUSTOMER_DRINKS_H
#define CUSTOMER_DRINKS_H

class CustomerDrink {
 private:
  int state_drink;

 public:
  void run(int& state_customer);
  int get_state_drink();
  CustomerDrink();
  ~CustomerDrink();
};

#endif