#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
 private:
  std::string name;
  double price;

 public:
  // default constructor
  Ingredient();

  // constructor
  Ingredient(std::string name, double price);

  // getter functions
  std::string get_name();
  double get_price();

  // setter functions
  void set_name(std::string name);
  void set_price(double price);

  // deconstructor
  ~Ingredient();
};

#endif