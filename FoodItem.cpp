#include "FoodItem.h"

// default constructor
FoodItem::FoodItem() : MenuItem("N/A", 0.0, 1) {}

// constructor without pre-made ingredients
FoodItem::FoodItem(string name, double price, int size)
    : MenuItem(name, price, size) {}

// contructor with pre-made ingredients
FoodItem::FoodItem(string name, double price, int size,
                   std::vector<Ingredient*> ingredients)
    : MenuItem(name, price, size), ingredients(ingredients) {}

// setter/ adder functions
void FoodItem::addIngredient(Ingredient& i) { ingredients.push_back(&i); }

// getter functions
Ingredient* FoodItem::get_ingredient(int index) {
  return ingredients[index];
}

// deconstructor
FoodItem::~FoodItem() {}