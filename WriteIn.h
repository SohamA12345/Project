#ifndef WRITE_IN_H
#define WRITE_IN_H

#include <fstream>

#include "MenuItem.h"
#include "IngredientList.h"


class WriteIn {
  private:

  public:
  // default constructor
  WriteIn();

  // write to a menu item list
  void write_menu_item_list(std::vector<string> list, std::string name); // by string vector 
  void write_menu_item_list(std::vector<MenuItem> list, std::string name); // by menu item vector

  // write to ingredient list text file
  void write_ingredient_list(IngredientList ingredient_list);

  // deconstructor
  ~WriteIn();
};

#endif