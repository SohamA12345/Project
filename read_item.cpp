#include "read_item.h"

#include <fstream>

#include "MenuItem.h"

std::vector<Ingredient> ReadItem::read_ingredient_list() {
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
  return list;
}

void ReadItem::read_menu_item(MenuItem* item, std::ifstream* inFile) {
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

Pasta ReadItem::read_pasta(std::string name) {
  std::string file_name = name + ".txt";
  std::ifstream inFile(name + ".txt");  // opens file with the same file name
  Pasta pasta;
  read_menu_item(
      &pasta, &inFile);  // calls general function and should return on line 3

  // unique to pasta, 2 attributes pasta type and pasta sauce
  int index = 4;
  int pasta_attributes = 2;
  std::string current_line;
  std::getline(inFile, current_line);
  for (int i = index; i < index + pasta_attributes; i++) {
    switch (index) {
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
  std::vector<Ingredient> list = read_ingredient_list();
  pasta.set_ingredient_list(list);
}

Pizza ReadItem::read_pizza() {}
