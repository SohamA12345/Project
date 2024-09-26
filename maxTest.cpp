#include <iostream>

#include "Pasta.h"
#include "Pizza.h"


int main() {



Ingredient gratedCheese("Grated Cheese", 2.0);
Ingredient gratedCheese("Grated Goat Cheese", 4.0);
Ingredient springOnion("Spring Onion", 1.50);
Ingredient onion("Onion", 0.55);

Pasta macNCheese("Mac and Cheese", 8.50, 1, "Cheese");

macNCheese.addIngredient(gratedCheese);
macNCheese.addIngredient(springOnion);

std::cout << macNCheese.get_ingredient(0)->get_name::endl;
std::cout << macNCheese.get_ingredient(0)->get_price() << std::endl;

Pizza pepperoniPizza("Peperoni Pizza", 12.0, 2, "Tomato Sauce", "Classic Crust");

pepperoniPizza.addIngredient(gratedCheese);

Ingredient pepperoni("Pepperoni", 0.50);

pepperoniPizza.addIngredient(pepperoni);
pepperoniPizza.addIngredient(gratedCheese);

std::cout << pepperoniPizza.get_item_name() << std::endl;
std::cout << pepperoniPizza.get_item_price() << std::endl;
std::cout << pepperoniPizza.get_ingredient(0)->get_name() << std::endl;
std::cout << pepperoniPizza.get_ingredient(0)->get_price() << std::endl;
 
  return 0;
}
