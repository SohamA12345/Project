#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <vector>

#include "Ingredient.h"
#include "MenuItem.h"

class FoodItem : public MenuItem {
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
  void addIngredient(Ingredient& i);

  // getter functions
  Ingredient* get_ingredient(int index);

  // deconstructor
  ~FoodItem();
};

#endif