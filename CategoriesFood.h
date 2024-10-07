#ifndef CATEGORIES_FOOD_H
#define CATEGORIES_FOOD_H

class CategoriesFood {
 private:
  int state_categories_food = 0;  // 0 mean no need to run portal again, 1 means
                                  // need to run again.
 public:
  void run(int& state_portal_food);
  int get_state_categories_food();
  CategoriesFood();
  ~CategoriesFood();
};

#endif