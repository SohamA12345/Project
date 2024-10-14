#ifndef WRITE_IN_H
#define WRITE_IN_H

#include <fstream>

#include "MenuItem.h"
#include "IngredientList.h"
#include "Pasta.h"
#include "Pizza.h"
#include "Burger.h"
#include "Noodle.h"
#include "Chips.h"
#include "Drink.h"
#include "Rice.h"
#include "Drink.h"
#include "ReadIn.h"


class WriteIn {
  private:

  public:
  // default constructor
  WriteIn();

  // write to a menu item list
  void write_menu_item_list(std::vector<string> list, std::string name); // by string vector 
  void write_menu_item_list(std::vector<MenuItem*> list, std::string name); // by menu item vector

  // write to ingredient list text file
  void write_ingredient_list(IngredientList ingredient_list);

  // write in menu item
  void write_menu_item(MenuItem* menu_item, std::ofstream* outfile);

  // write in pasta
  void write_pasta(Pasta pasta);

  // write in pizza
  void write_pizza(Pizza pizza);

    // write in burger
  void write_burger(Burger burger);

    // write in noodle
  void write_noodle(Noodle noodle);

    // write in chips
  void write_chips(Chips chips);

    // write in rice
  void write_rice(Rice rice);

    // write in drink
  void write_drink(Drink drink);

// create pasta
void create_pasta(Pasta pasta);

// create pizza
void create_pizza(Pizza pizza);

// create burger
void create_burger(Burger burger);

// create noodle
void create_noodle(Noodle noodle);

// create chips
void create_chips(Chips chips);

// create rice
void create_rice(Rice rice);

// create drink
void create_drink(Drink drink);

  // deconstructor
  ~WriteIn();
};

#endif