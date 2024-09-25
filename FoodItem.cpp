#include "FoodItem.h"

// default constructor
FoodItem::FoodItem(): MenuItem("N/A", 0.0, 1) {}

// constructor without pre-made ingredient list
FoodItem::FoodItem(string name, double price, int size) : MenuItem(name, price, size) {}

// contructor with pre-made ingredient list
FoodItem::FoodItem(string name, double price, int size, std::vector<Ingredient*> ingredientList) : MenuItem(name, price, size), ingredientList(ingredientList){}

// setter/ adder functions
void FoodItem::addIngredient(Ingredient &i){
  ingredientList.push_back(&i);
}

// getter functions
Ingredient* FoodItem::get_ingredient(int index){
  return ingredientList[index];
}

std::string FoodItem::get_ingredientName(int index){
  return get_ingredient(index)->get_name();
}

// deconstructor
FoodItem::~FoodItem(){}