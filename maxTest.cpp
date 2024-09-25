#include <iostream>

#include "Pasta.h"
#include "Pizza.h"


int main() {

Ingredient gratedCheese("Grated Cheese", 2.0);
Ingredient springOnion("Spring Onion", 1.50);
Ingredient onion("Onion", 0.55);

Pasta macNCheese("Mac and Cheese", 8.50, 1, "Cheese");

macNCheese.addIngredient(gratedCheese);
macNCheese.addIngredient(springOnion);

std::cout << macNCheese.get_ingredient(0)->get_name() << std::endl;


  return 0;
}