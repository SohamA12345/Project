#include <iostream>
#include <string>
#include<vector>

#include "Ingredient.h"



class Pasta {
  private:
    double price;
    std::string name;
    std::vector<Ingredient*> ingredientList;

    // pasta exclusive
    std::string pastaSauce;

  public:

  Pasta() : price(9999999), name("NoName"), pastaSauce("No Sauce")  {}

  Pasta(double price, std::string name, std::string pastaSauce) : price(price), name(name), pastaSauce(pastaSauce) {}

  void addIngredient(Ingredient &i) {
    ingredientList.push_back(&i);
  }

  Ingredient* get_ingredient(int index) {
    return ingredientList[index];
  }

  std::string get_ingredientName(int index) {
      return get_ingredient(index)->get_name();
  }

};


int main() {

Ingredient tomato("Tomato", 2.0);
Ingredient mushroom("Mushroom", 1.50);
Ingredient onion("Onion", 0.55);

Pasta yummy(7.5, "Yummy", "Tomato Sauce");

yummy.addIngredient(tomato);
yummy.addIngredient(mushroom);
yummy.addIngredient(onion);

  std::cout << yummy.get_ingredientName(2) << std::endl;

  return 0;
}