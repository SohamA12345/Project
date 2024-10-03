#ifndef PASTA_H
#define PASTA_H

#include "FoodItem.h"

class Pasta : public FoodItem {
 private:
  std::string pastaSauce;

 public:
  // default constructor
  Pasta();

  // constructor without ingredient list
  Pasta(std::string name, double price, int size, std::string pastaSauce);

  // constructor with ingredient list
  Pasta(std::string name, double price, int size, std::string pastaSauce,
        std::vector<Ingredient> ingredientList);

  // getter functions
  std::string get_pastaSauce();

  // setter functions
  void set_pastaSauce(std::string pastaSauce);

  // deconstructor
  ~Pasta();
};

#endif