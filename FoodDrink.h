#ifndef FOOD_DRINK_H
#define FOOD_DRINK_H

class FoodDrink {
 private:
  // 0 mean no need to run portal again, 1 means portal needs to rerun
  int state_portal_food = 0;  

 public:
  // runs portal
  void run(int& state_portal_manager);

  // get the value of state_portal_food (0 or 1)
  int get_state_portal_food();

  // default constructor and destructor
  FoodDrink();
  ~FoodDrink();
};

#endif