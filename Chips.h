#ifndef CHIPS_H
#define CHIPS_H

#include "FoodItem.h"

class Chips : public FoodItem {
 private:
  std::string chips_cut;
  std::string chips_seasoning;

 public:
  // default constructor
  Chips();

  // constructor without ingredient list
  Chips(std::string name, double price, int size, std::string chips_cut,
        std::string chips_seasoning);

  // constructor with ingredient list
  Chips(std::string name, double price, int size, std::string chips_cut,
        std::string chips_seasoning, std::vector<Ingredient> ingredients);

  // getter functions
  std::string get_chips_cut();
  std::string get_chips_seasoning();

  // setter functions
  void set_chips_cut(std::string chips_type);
  void set_chips_seasoning(std::string set_chips_seasoning);

  // deconstructor
  ~Chips();
};

#endif
