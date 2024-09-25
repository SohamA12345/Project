#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include "MenuItem.h"
#include "Ingredient.h"

#include <vector>

class FoodItem : public MenuItem {
protected:
  std::vector<Ingredient*> ingredientList;
public:
// default constructor
FoodItem();

// constructor without pre-made ingredient list
FoodItem(string name, double price, int size);

// contructor with pre-made ingredient list
FoodItem(string name, double price, int size, std::vector<Ingredient*> ingredientList);

// setter/ adder functions
void addIngredient(Ingredient &i);

// getter functions
Ingredient* get_ingredient(int index);

std::string get_ingredientName(int index);

// deconstructor
~FoodItem();

};

#endif