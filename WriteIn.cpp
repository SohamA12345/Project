#include "WriteIn.h"

// default contructor
WriteIn::WriteIn() {}

// write to a menu item list
void WriteIn::write_menu_item_list(std::vector<string> list,
                                   std::string name) {  // by string vector
  std::string file_name = name + ".txt";
  std::ofstream outFile(file_name);

  int list_length = list.size();
  for (int i = 0; i < list_length; i++) {
    outFile << list[i] << std::endl;
  }
}

void WriteIn::write_menu_item_list(std::vector<MenuItem> list,
                                   std::string name) {  // by menu item vector
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

// write in menu item: write in name, price and size
void WriteIn::write_menu_item(MenuItem* menu_item, std::ofstream* out_file) {
  *out_file << menu_item->get_item_name() << std::endl;
  *out_file << menu_item->get_item_price() << std::endl;
  int item_size_number = menu_item->get_item_size();
  std::string item_size;
  if (item_size_number == 1) {
    item_size = "small";
  } else if (item_size_number == 2) {
    item_size = "medium";
  } else if (item_size_number == 3) {
    item_size = "large";
  } else {
    item_size = "small";
  }
  *out_file << item_size << std::endl;
}

// write in pasta
void WriteIn::write_pasta(Pasta pasta) {
  std::string file_name = pasta.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&pasta, &out_file);

  out_file << pasta.get_pasta_type() << std::endl;
  out_file << pasta.get_pasta_sauce() << std::endl;

  int no_ingredients = pasta.get_ingredient_list().size();
  out_file << no_ingredients << std::endl;
  for (int i = 0; i < no_ingredients; i++) {
    out_file << pasta.get_ingredient(i).get_name() << std::endl;
  }

  out_file.close();
}

// write in pizza
void WriteIn::write_pizza(Pizza pizza) {
  std::string file_name = pizza.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&pizza, &out_file);

  out_file << pizza.get_pizza_sauce() << std::endl;
  out_file << pizza.get_pizza_cheese() << std::endl;
  int no_ingredients = pizza.get_ingredient_list().size();
  out_file << no_ingredients << std::endl;
  for (int i = 0; i < no_ingredients; i++) {
    out_file << pizza.get_ingredient(i).get_name() << std::endl;
  }

  out_file.close();
}

// deconstructor
WriteIn::~WriteIn() {}