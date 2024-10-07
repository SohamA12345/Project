#ifndef CUSTOMER_FOOD_DRINK_H
#define CUSTOMER_FOOD_DRINK_H

class CustomerFoodDrink
{
private:
  int state_customer = 0;
public:
  void run(int& state_customer_login);
  int get_state_customer();
  CustomerFoodDrink();
  ~CustomerFoodDrink();
};

#endif