#ifndef PIZZA_H
#define PIZZA_H

#include "FoodItem.h"

class Pizza : public FoodItem {
 private:
  std::string pizzaSauce;
  std::string pizzaBase;

 public:
  // default constructor
  Pizza();

  // constructor without ingredient list
  Pizza(std::string name, double price, int size, std::string pizzaSauce,
        std::string pizzaBase);

  // constructor with ingredient list
  Pizza(std::string name, double price, int size, std::string pizzaSauce,
        std::string pizzaBase, std::vector<Ingredient> ingredientList);

  // getter functions
  std::string get_pizzaSauce();
  std::string get_pizzaBase();

  // setter functions
  void set_pizzaSauce(std::string pastaSauce);
  void set_pizzaBase(std::string pizzaBase);

  // deconstructor
  ~Pizza();
};
#endif