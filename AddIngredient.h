#ifndef ADD_INGREDIENT_H
#define ADD_INGREDIENT_H

class AddIngredient {
 private:
  // 0 mean no need to run portal again, 1 means need to run again.
  int add_ingredient = 0;

 public:
  // runs the portal
  void run(int& state_portal_food);

  // returns the current value of add_ingredient
  int get_add_ingredient();

  // default constructor and destructor
  AddIngredient();
  ~AddIngredient();
};

#endif