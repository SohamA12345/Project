#ifndef INGREDIENT_H
#define INGREDIENT_H

#include<string>
#include<vector>

class Ingredient {
private:
  std::string name;
  double price;

public:

  Ingredient();
  Ingredient(std::string name, double price);

  std::string get_name();
  double get_price();

  void set_name(std::string name);
  void set_price(double price);
  
};

#endif