#ifndef INGREDIENT_LIST_H
#define INGREDIENT_LIST_H

#include "Ingredient.h"
#include <vector>

class IngredientList {
  private:
    std::vector<Ingredient> ingredientList;
  public:
  // default constructor
  IngredientList();

  // setter functions
  void set_ingredient(Ingredient i); 

// getter functions
  Ingredient* get_ingredient(int index); // returns address of ingredient at the index 

// remove functions
void remove_ingredient(int index);
void remove_ingredient(std::string name);

  // deconstructor
  ~IngredientList();
};

#endif