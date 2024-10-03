#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <vector>

#include "Ingredient.h"
#include "MenuItem.h"

class FoodItem : public MenuItem {
 protected:
  std::vector<Ingredient> ingredients;

 public:
  // default constructor
  FoodItem();

  // constructor without pre-made ingredients
  FoodItem(string name, double price, int size);

  // contructor with pre-made ingredients
  FoodItem(string name, double price, int size,
           std::vector<Ingredient> ingredients);

  // setter funciton
  void set_ingredient_list(vector<Ingredient> list);

  // adder functions
  void add_ingredient(Ingredient i);

  // getter functions
  Ingredient get_ingredient(int index);

  vector<Ingredient> get_ingredient_list();

  double calculate_item_price();

 // print ingredients functions
 void print_ingredients_and_price();

  // deconstructor
  ~FoodItem();
};

#endif