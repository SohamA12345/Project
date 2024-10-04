#ifndef PIZZA_H
#define PIZZA_H

#include "FoodItem.h"

class Pizza : public FoodItem {
 private:
  std::string pizza_sauce;
  std::string pizza_cheese;

 public:
  // default constructor
  Pizza();

  // constructor without ingredient list
  Pizza(std::string name, double price, int size, std::string pizza_sauce,
        std::string pizza_cheese);

  // constructor with ingredient list
  Pizza(std::string name, double price, int size, std::string pizza_sauce,
        std::string pizza_cheese, std::vector<Ingredient> ingredientList);

  // getter functions
  std::string get_pizza_sauce();
  std::string get_pizza_cheese();

  // setter functions
  void set_pizza_sauce(std::string pasta_sauce);
  void set_pizza_cheese(std::string pizza_cheese);

  // deconstructor
  ~Pizza();
};
#endif