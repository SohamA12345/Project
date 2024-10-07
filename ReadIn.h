#ifndef READ_IN_H
#define READ_IN_H

#include <fstream>

#include "IngredientList.h"

#include "Pasta.h"
#include "Pizza.h"
#include "Burger.h"

class ReadIn {
private:

public:
// default constructor
ReadIn();

// read in the ingredient list
IngredientList read_ingredient_list();

// read in name, price and size of menu item
void read_menu_item(MenuItem* item, std::ifstream* inFile); // reads in information that all menu items have

// read in a menu item list
std::vector<string> read_menu_item_list(std::string file_name);

// read in a pasta
Pasta read_pasta(std::string name);

// read in a pizza
Pizza read_pizza(std::string name);

// read in burger
Burger read_burger(std::string name);

// deconstructor
~ReadIn();

};

#endif