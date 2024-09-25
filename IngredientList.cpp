#include "IngredientList.h"

  // default constructor
  IngredientList::IngredientList() {}

  // setter functions
  void IngredientList::set_ingredient(Ingredient i) {}

// getter functions
  Ingredient* IngredientList::get_ingredient(int index) {} // returns address of ingredient at the index 

// remove functions
void IngredientList::remove_ingredient(int index) {}
void IngredientList::remove_ingredient(std::string name) {}

  // deconstructor
  IngredientList::~IngredientList() {}