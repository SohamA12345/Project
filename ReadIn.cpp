#include "ReadIn.h"

#include "MenuItem.h"

// default constructor
ReadIn::ReadIn() {}

// read in the ingredient list
IngredientList ReadIn::read_ingredient_list() {
  std::ifstream inFile("ingredientlist.txt");
  vector<Ingredient> list;
  int line_count = 0;
  std::string current_line;
  int index = 0;
  while (std::getline(inFile, current_line)) {  // loops while it reads a line
    line_count++;
    if (line_count % 2 == 1) {
      list.push_back(Ingredient());
      list[index].set_name(current_line);
    } else {
      list[index].set_price(stod(current_line));
      index++;
    }
  }
  IngredientList ingredient_list(list);
  return ingredient_list;
}

// read in menu items name, price and size
void ReadIn::read_menu_item(MenuItem* item, std::ifstream* inFile) {
  int line_count = 0;
  std::string current_line;
  for (int i = 0; i < 3; i++) {
    std::getline(*inFile, current_line);  // stores the current line
    line_count++;
    switch (line_count) {
      case 1:
        item->set_item_name(current_line);  // set the name to the first line
        break;
      case 2:
        item->set_item_price(
            stod(current_line));  // set the price to the first line
        break;
      case 3:
        item->set_item_size(current_line);  // set the size to the first line
        break;
      default:
        break;
    }
  }
}

// read in a menu item list
std::vector<std::string> ReadIn::read_menu_item_list(std::string name) {
  // read in file with file name given
  std::string file_name = name + ".txt";
  std::ifstream inFile(file_name);

std::vector<std::string> list;
  std::string current_line;
  // read line until all lines are read
  while (std::getline(inFile, current_line)) {
    list.push_back(current_line);
  }  

  return list;
}

// read in a pasta from file
Pasta ReadIn::read_pasta(std::string name) {
  std::string file_name = name + ".txt";
  std::ifstream inFile(name + ".txt");  // opens file with the same file name
  Pasta pasta;
  read_menu_item(
      &pasta, &inFile);  // calls general function and should return on line 3

  // unique to pasta, 2 attributes pasta type and pasta sauce
  int index = 4;
  int pasta_attributes = 2;
  std::string current_line;
  for (int i = index; i < index + pasta_attributes; i++) {
    std::getline(inFile, current_line);
    switch (i) {
      case 4:
        pasta.set_pasta_type(current_line);
        break;
      case 5:
        pasta.set_pasta_sauce(current_line);
        break;
      default:
        break;
    }
  }

  // read in ingredient list
  IngredientList ingredient_list = read_ingredient_list();
  pasta.set_ingredient_list(ingredient_list.get_ingredient_list());

  return pasta;
}

// read in pizza from a file
Pizza ReadIn::read_pizza(std::string name) {
  std::string file_name = name + ".txt";
  std::ifstream inFile(name + ".txt");  // opens file with the same file name
  Pizza pizza;
  read_menu_item(
      &pizza, &inFile);  // calls general function and should return on line 3

  // unique to pizza, 2 attributes pizza sauce and pizza cheese
  int index = 4;
  int pizza_attributes = 2;
  std::string current_line;
  for (int i = index; i < index + pizza_attributes; i++) {
    std::getline(inFile, current_line);
    switch (i) {
      case 4:
        pizza.set_pizza_sauce(current_line);
        break;
      case 5:
        pizza.set_pizza_cheese(current_line);
        break;
      default:
        break;
    }
  }
  // read in ingredient list
  IngredientList ingredient_list = read_ingredient_list();
  pizza.set_ingredient_list(ingredient_list.get_ingredient_list());

  return pizza;
}

// read in burger from file
Burger ReadIn::read_burger(std::string name) {
  std::string file_name = name + ".txt";
  std::ifstream inFile(name + ".txt");  // opens file with the same file name
  Burger burger;
  read_menu_item(
      &burger, &inFile);  // calls general function and should return on line 3

  // unique to burger, 2 attributes burger bun and burger meat
  int index = 4;
  int burger_attributes = 2;
  std::string current_line;
  for (int i = index; i < index + burger_attributes; i++) {
    std::getline(inFile, current_line);
    switch (i) {
      case 4:
        burger.set_burger_bun(current_line);
        break;
      case 5:
        burger.set_burger_meat(current_line);
        break;
      default:
        break;
    }
  }
  // read in ingredient list
  IngredientList ingredient_list = read_ingredient_list();
  burger.set_ingredient_list(ingredient_list.get_ingredient_list());

  return burger;
}

// deconstructor
ReadIn::~ReadIn() {}
