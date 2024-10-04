#ifndef NOODLE_H
#define NOODLE_H

#include "FoodItem.h"

  class Noodle : public FoodItem {
    private:
    std::string noodle_type;
    std::string noodle_soup;

   public:
   // default constructor
  Noodle();

  // constructor without ingredient list
  Noodle(std::string name, double price, int size, std::string noodle_type,
        std::string noodle_soup);

  // constructor with ingredient list
  Noodle(std::string name, double price, int size, std::string noodle_type,
        std::string noodle_soup, std::vector<Ingredient> ingredients);

  // getter functions
  std::string get_noodle_type();
  std::string get_noodle_soup();

  // setter functions
  void set_noodle_type(std::string noodle_type);
  void set_noodle_soup(std::string noodle_soup);

  // deconstructor
  ~Noodle();

  };

#endif