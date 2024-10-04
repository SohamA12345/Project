#ifndef FOOD_DRINK_H
#define FOOD_DRINK_H

class FoodDrink {
 private:
  int state_portal_food = 0;  // 0 mean no need to run portal again, 1 means
                              // need to run again.
 public:
  void run(int& state_portal_manager);
  int get_state_portal_food();
  FoodDrink(/* args */);
  ~FoodDrink();
};

#endif