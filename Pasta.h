#ifndef PASTA_H
#define PASTA_H

#include "FoodItem.h"

class Pasta : public FoodItem {
 private:
  std::string pasta_type;
  std::string pasta_sauce;

 public:
  // default constructor
  Pasta();

  // constructor without ingredient list
  Pasta(std::string name, double price, int size, std::string pasta_type, std::string pasta_sauce);

  // constructor with ingredient list
  Pasta(std::string name, double price, int size, std::string pasta_type, std::string pasta_sauce,
        std::vector<Ingredient> ingredientList);

  // getter functions
      std::string get_pasta_type();
      std::string get_pasta_sauce();

  // setter functions
  void set_pasta_type(std::string pasta_type);
  void set_pasta_sauce(std::string pasta_sauce);

  // deconstructor
  ~Pasta();
};

#endif