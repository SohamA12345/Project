#include "read_item.h"
#include "MenuItem.h"

#include <fstream>

std::vector<Ingredient> ReadItem::read_ingredient_list(
    int ingredient_line_start) {}

void ReadItem::read_menu_item(MenuItem* item, std::ifstream* inFile) {
  int line_count = 0;
  std::string current_line;
  for (int i = 0; i < 3; i++) {
    std::getline(*inFile, current_line);  // stores the current line
    line_count++;
    switch (line_count) { 
      case 1:
        item->set_item_name(current_line); // set the name to the first line
        break;
      case 2:
        item->set_item_price(stod(current_line)); // set the price to the first line
        break;
      case 3:
        item->set_item_size(current_line); // set the size to the first line
        break;
      default:
        break;
    }
  }
}

Pasta ReadItem::read_pasta(std::string name) {
  std::string file_name = name + ".txt";
  std::ifstream inFile(name + ".txt"); // opens file with the same file name
  Pasta pasta;
  read_menu_item(&pasta, &inFile); // calls general function and should return on line 3

  // unique to pasta, 2 attributes pasta type and pasta sauce
  int index = 3;
  int pasta_attributes = 2;
  for (int i = 0; i < pasta_attributes; i++) {
    switch (current_line)
    {
    case /* constant-expression */:
      /* code */
      break;
    
    default:
      break;
    }
  }

}

Pizza ReadItem::read_pizza() {}
