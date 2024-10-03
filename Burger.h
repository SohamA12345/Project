#ifndef BURGER_H
#define BURGER_H

#include "FoodItem.h"

class Burger : public FoodItem{
   private:
    std::string burger_bun;
    std::string burger_meat;

   public:
   // default constructor
  Burger();

  // constructor without ingredient list
  Burger(std::string name, double price, int size, std::string burger_bun,
        std::string burger_meat);

  // constructor with ingredient list
  Burger(std::string name, double price, int size, std::string burger_bun,
        std::string burger_meat, std::vector<Ingredient> ingredientList);

  // getter functions
  std::string get_burger_bun();
  std::string get_burger_meat();

  // setter functions
  void set_burger_bun(std::string burger_bun);
  void set_burger_meat(std::string burger_meat);

  // deconstructor
  ~Burger();
};

#endif