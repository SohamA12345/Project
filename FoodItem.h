#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <vector>

#include "ingredient.h"
#include "menu_item.h"

class FoodItem : public menu_item {
 protected:
  std::vector<Ingredient*> ingredients;

 public:
  // default constructor
  FoodItem();

  // constructor without pre-made ingredients
  FoodItem(string name, double price, int size);

  // contructor with pre-made ingredients
  FoodItem(string name, double price, int size,
           std::vector<Ingredient*> ingredients);

  // adder functions
  void add_ingredient(Ingredient* i);

  // getter functions
  Ingredient* get_ingredient(int index);

  double calculate_item_price();

 // print ingredients functions
 void print_ingredients_and_price();

  // deconstructor
  ~FoodItem();
};

#endif