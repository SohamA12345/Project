#ifndef RICE_H
#define RICE_H

#include "FoodItem.h"

class Rice: public FoodItem {
private:
  std::string rice_type;
public:
 // default constructor
  Rice();

  // constructor without ingredient list
  Rice(std::string name, double price, int size, std::string rice_type);

  // constructor with ingredient list
  Rice(std::string name, double price, int size, std::string rice_type, std::vector<Ingredient> ingredients);

  // getter functions
  std::string get_rice_type();

  // setter functions
  void set_rice_type(std::string rice_type);

  // deconstructor
  ~Rice();



};

#endif