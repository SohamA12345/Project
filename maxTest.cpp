#include <iostream>


#include "Pasta.h"
#include "Pizza.h"


int main() {

Ingredient gratedCheese("Grated Cheese", 2.0);
Ingredient gratedGoatCheese("Grated Goat Cheese", 4.0);
Ingredient springOnion("Spring Onion", 1.50);
Ingredient onion("Onion", 0.55);

Pasta macNCheese("Mac and Cheese", 8.50, 1, "Cheese");

Pizza pepperoniPizza("Peperoni Pizza", 12.0, 2, "Tomato Sauce", "Classic Crust");

Ingredient pepperoni("Pepperoni", 0.50);
 
// temporary
while (1==1) {

std::cout << "Write pizza or pasta to add one: ";
std::string user_input;
std::cin >> user_input;

if (user_input == "pizza") {
  
} else if(user_input == "pasta") {

} else {
  std::cout << "Please try again." << std::endl;
}

}


  return 0;
}
