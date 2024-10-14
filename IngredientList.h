#ifndef INGREDIENT_LIST_H
#define INGREDIENT_LIST_H

#include <vector>

#include "Ingredient.h"

class IngredientList {
 private:
  std::vector<Ingredient> ingredients;

 public:
  // default constructor
  IngredientList();

  // constructor
  IngredientList(std::vector<Ingredient> ingredients);

  // setter functions
  void set_ingredient_list(std::vector<Ingredient> ingredients);
  // getter functions
  std::vector<Ingredient> get_ingredient_list();

  // add ingredient
  void add_ingredient(Ingredient ingredient);           // by ingredient
  void add_ingredient(std::string name, double price);  // by name and price

  // remove ingredient
  void remove_ingredient(std::string name);

  // deconstructor
  ~IngredientList();
};

#endif