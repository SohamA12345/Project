#ifndef ADD_INGREDIENT_H
#define ADD_INGREDIENT_H

class AddIngredient {
 private:
  int add_ingredient =
      0;  // 0 mean no need to run portal again, 1 means need to run again.
 public:
  void run(int& state_portal_food);
  int get_add_ingredient();
  AddIngredient();
  ~AddIngredient();
};

#endif