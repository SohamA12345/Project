#include <iostream>

#include "Pasta.h"
#include "Pizza.h"

int main() {
  std::vector<Pizza> pizzaList;

  // temporary

  std::string input_name;
  double input_price;
  int input_size;
  std::string input_sauce;
  std::string input_base;

  std::cout << "Write pizza to add one ";
  std::string user_input;
  std::getline(std::cin, user_input);

  if (user_input == "pizza") {
    std::cout << "Enter pizza name: ";
    std::cin.ignore();
    std::getline(std::cin, input_name);
    std::cout << "Enter pizza price ";
    std::cin >> input_price;
    std::cout << "Enter pizza size: ";
    std::cin >> input_size;
    std::cout << "Enter pizza sauce: ";
    std::cin.ignore();
    std::getline(std::cin, input_sauce);
    std::cout << "Enter pizza base: ";
    std::cin.ignore();
    std::getline(std::cin, input_base);
    pizzaList.push_back(
        Pizza(input_name, input_price, input_size, input_sauce, input_base));
  } else if (user_input == "pasta") {
    std::cout << "Please try again." << std::endl;
  } else {
    std::cout << "Please try again." << std::endl;
  }

  std::vector<Ingredient> ingerdientList;

  for (int i = 0; i < 1; i++) {
    std::cout << "Write i to add one: ";
    std::cin >> user_input;
    if (user_input == "i") {
      std::cout << "Enter ingeredient name: ";
      std::string input_name;
      std::cin.ignore();
      std::getline(std::cin, input_name);
      std::cout << "Enter ingredient price ";
      double input_price;
      std::cin >> input_price;
      ingerdientList.push_back(Ingredient(input_name, input_price));
      pizzaList[i].add_ingredient(&ingerdientList[i]);
    } else {
      std::cout << "fail" << std::endl;
    }
  }


  std::cout << pizzaList[0].get_item_name() << std::endl;
  pizzaList[0].print_ingredients_and_price();

  return 0;
}
