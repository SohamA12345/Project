#ifndef CATEGORIES_FOOD_H
#define CATEGORIES_FOOD_H

class CategoriesFood {
 private:
  // 0 mean no need to run portal again, 1 means need to run again.
  int state_categories_food = 0;  
 public:
  // runs the portal
  void run(int& state_portal_food);

  // return the state of portal (0 or 1)
  int get_state_categories_food();

  // default constructor/destructor
  CategoriesFood();
  ~CategoriesFood();
};

#endif