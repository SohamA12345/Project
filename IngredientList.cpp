#include "IngredientList.h"

// default constructor
IngredientList::IngredientList() : ingredients() {}

// constructor
IngredientList::IngredientList(std::vector<Ingredient> ingredients)
    : ingredients(ingredients) {}

// setter functions
void IngredientList::set_ingredient_list(std::vector<Ingredient> ingredients) {
  this->ingredients = ingredients;
}
// getter functions
std::vector<Ingredient> IngredientList::get_ingredient_list() {
  return this->ingredients;
}

// add ingredient by ingredient
void IngredientList::add_ingredient(Ingredient ingredient) {
  ingredients.push_back(ingredient);
}
// add ingredient by name and price
void IngredientList::add_ingredient(std::string name, double price) {
  ingredients.push_back(Ingredient(name, price));
}

// remove ingredient
void IngredientList::remove_ingredient(std::string name) {
  int index = 0;
  bool found_ingredient = false;
  // search thorugh vector and delete first instance with name
  while (index < ingredients.size() && found_ingredient == false) {
    if (ingredients[index].get_name() == name) {
      ingredients.erase(ingredients.begin() +
                        index);  // remove ingredient at corresponding index
      found_ingredient = true;
    }
    index++;
  }
}

// deconstructor
IngredientList::~IngredientList() {}
