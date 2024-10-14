#ifndef READ_IN_H
#define READ_IN_H

#include <fstream>

#include "Burger.h"
#include "Chips.h"
#include "Drink.h"
#include "IngredientList.h"
#include "Noodle.h"
#include "Pasta.h"
#include "Pizza.h"
#include "Rice.h"

class ReadIn {
 private:
 public:
  // default constructor
  ReadIn();

  // read in the ingredient list
  IngredientList read_ingredient_list();

  // read in name, price and size of menu item
  void read_menu_item(
      MenuItem* item,
      std::ifstream* inFile);  // reads in information that all menu items have

  // read in a menu item list
  std::vector<string> read_menu_item_list(std::string file_name);

// find ingredients
std::vector<Ingredient> find_ingredients(int item_attributes, std::ifstream* inFile);

  // read in a pasta
  Pasta read_pasta(std::string name);

  // read in a pizza
  Pizza read_pizza(std::string name);

  // read in burger
  Burger read_burger(std::string name);

  // read in noodle
  Noodle read_noodle(std::string name);

  // read in chips
  Chips read_chips(std::string name);

  // read in rice
  Rice read_rice(std::string name);

  // read in drink
  Drink read_drink(std::string name);

  // deconstructor
  ~ReadIn();
};

#endif