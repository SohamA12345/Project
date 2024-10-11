#include "FoodItem.h"

// default constructor
FoodItem::FoodItem() : MenuItem("N/A", 0.0, 1) {}

// constructor without pre-made ingredients
FoodItem::FoodItem(string name, double price, int size)
    : MenuItem(name, price, size) {}

// contructor with pre-made ingredients
FoodItem::FoodItem(string name, double price, int size,
                   std::vector<Ingredient> ingredients)
    : MenuItem(name, price, size), ingredients(ingredients) {}

// setter/ adder functions
void FoodItem::add_ingredient(Ingredient i) { ingredients.push_back(i); }

void FoodItem::set_ingredient_list(vector<Ingredient> list) {
  this->ingredients = list;
}

void FoodItem::remove_ingredient(int i) {ingredients.erase(ingredients.begin() + i);}

// getter functions
Ingredient FoodItem::get_ingredient(int index) {
  return ingredients[index];
}

vector<Ingredient> FoodItem::get_ingredient_list() {
  return ingredients;
}

double FoodItem::calculate_item_price() {
  double total_price = get_item_price() * (1 + 0.25 * (item_size - 1)); // calcualte price based on size
  int vector_length = ingredients.size();
  for (int i = 0; i < vector_length; i++) {
    total_price += ingredients[i].get_price();
  }
  return total_price;
}

// print ingredients function
void FoodItem::print_ingredients_and_price() {
  int vector_length = ingredients.size();
  if (vector_length == 0) { // no ingredients in item
    std::cout << "No ingredients added!" << std::endl;
  } else if (vector_length < 0) { // negative ingredients 
    std::cout << "Error" << std::endl;
  } else {
    for (int i = 0; i < vector_length; i++) { // print name + price
      cout << ingredients[i].get_name() << " | $" << ingredients[i].get_price() << std::endl;
    }
  }
}

// deconstructor
FoodItem::~FoodItem() {}