#ifndef CUSTOMER_CATEGORIES_FOOD_H
#define CUSTOMER_CATEGORIES_FOOD_H

class CustomerCategoriesFood
{
private:
  int state_categories = 0;
public:
  void run(int& state_customer);
  int get_state_categories();

  CustomerCategoriesFood(/* args */);
  ~CustomerCategoriesFood();
};

#endif