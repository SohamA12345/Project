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

IngredientList read_ingredient_list();

void read_menu_item(MenuItem* item, std::ifstream* inFile); // reads in information that all menu items have

Pasta read_pasta(std::string name);

Pizza read_pizza(std::string name);

Burger read_burger(std::string name);

// deconstructor
~ReadIn();

};

#endif