#ifndef READ_ITEM_H
#define READ_ITEM_H

#include "Pasta.h"
#include "Pizza.h"

class ReadItem {
private:

public:

std::vector<Ingredient> read_ingredient_list();

void read_menu_item(MenuItem* item, std::ifstream* inFile); // reads in information that all menu items have

Pasta read_pasta(std::string name);

Pizza read_pizza(std::string name);


};

#endif