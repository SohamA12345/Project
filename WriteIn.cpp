#include "WriteIn.h"

// default contructor
WriteIn::WriteIn() {}

// write to a menu item list
  void WriteIn::write_menu_item_list(std::vector<string> list, std::string name) { // by string vector 
      std::string file_name = name + ".txt";
      std::ofstream outFile(file_name);

      int list_length = list.size();
      for (int i = 0; i < list_length; i++) {
        outFile << list[i] << std::endl;
      }
  } 

  void WriteIn::write_menu_item_list(std::vector<MenuItem> list, std::string name) { // by menu item vector

  }

// write to ingredient list text file
void WriteIn::write_ingredient_list(IngredientList ingredient_list) {
  std::vector<Ingredient> list = ingredient_list.get_ingredient_list();
  std::ofstream outFile("ingredientlist.txt");
  int list_length = list.size();
  for (int i = 0; i < list_length; i++) {
    outFile << list[i].get_name() << std::endl;
    outFile << list[i].get_price() << std::endl;
  }
}

// deconstructor
WriteIn::~WriteIn() {}