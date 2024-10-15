#include "WriteIn.h"

// default contructor
WriteIn::WriteIn() {}

// write to a menu item list by string of ingredient names
void WriteIn::write_menu_item_list(std::vector<string> list,
                                   std::string name) {  // by string vector
  std::string file_name = name + ".txt";  // append .txt to end of string
  std::ofstream outFile(file_name);

  int list_length = list.size();
  for (int i = 0; i < list_length; i++) {
    outFile << list[i]
            << std::endl;  // write ingredient name to corresponding line
  }
}

// write to a menu item list by ingredients
void WriteIn::write_menu_item_list(std::vector<MenuItem*> list,
                                   std::string name) {  // by menu item vector
  std::string file_name = name + ".txt";  // append .txt to end of string
  std::ofstream outFile(file_name);       // open file with name

  int list_length = (list).size();
  for (int i = 0; i < list_length; i++) {
    outFile << list[0][i].get_item_name()
            << std::endl;  // write ingredient name to corresponding line
  }
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

// write in burger
void WriteIn::write_burger(Burger burger) {
  std::string file_name = burger.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&burger, &out_file);

  out_file << burger.get_burger_bun() << std::endl;
  out_file << burger.get_burger_meat() << std::endl;
  int no_ingredients = burger.get_ingredient_list().size();
  out_file << no_ingredients << std::endl;
  for (int i = 0; i < no_ingredients; i++) {
    out_file << burger.get_ingredient(i).get_name() << std::endl;
  }

  out_file.close();
}

// write in noodle
void WriteIn::write_noodle(Noodle noodle) {
  std::string file_name = noodle.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&noodle, &out_file);

  out_file << noodle.get_noodle_type() << std::endl;
  out_file << noodle.get_noodle_soup() << std::endl;
  int no_ingredients = noodle.get_ingredient_list().size();
  out_file << no_ingredients << std::endl;
  for (int i = 0; i < no_ingredients; i++) {
    out_file << noodle.get_ingredient(i).get_name() << std::endl;
  }

  out_file.close();
}

// write in chips
void WriteIn::write_chips(Chips chips) {
  std::string file_name = chips.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&chips, &out_file);

  out_file << chips.get_chips_cut() << std::endl;
  out_file << chips.get_chips_seasoning() << std::endl;
  int no_ingredients = chips.get_ingredient_list().size();
  out_file << no_ingredients << std::endl;
  for (int i = 0; i < no_ingredients; i++) {
    out_file << chips.get_ingredient(i).get_name() << std::endl;
  }

  out_file.close();
}

// write in rice
void WriteIn::write_rice(Rice rice) {
  std::string file_name = rice.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&rice, &out_file);

  out_file << rice.get_rice_type() << std::endl;
  int no_ingredients = rice.get_ingredient_list().size();
  out_file << no_ingredients << std::endl;
  for (int i = 0; i < no_ingredients; i++) {
    out_file << rice.get_ingredient(i).get_name() << std::endl;
  }

  out_file.close();
}

// write in drink
void WriteIn::write_drink(Drink drink) {
  std::string file_name = drink.get_item_name() + ".txt";
  std::ofstream out_file(file_name);  // make write file object

  write_menu_item(&drink, &out_file);

  out_file << drink.get_sugar() << std::endl;
  out_file << drink.show_ice() << std::endl;

  out_file.close();
}

// create pasta
void WriteIn::create_pasta(Pasta pasta) {
  write_pasta(pasta);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("pastalist");
  list.push_back(pasta.get_item_name());
  write_menu_item_list(list, "pastalist");
}

// create pizza
void WriteIn::create_pizza(Pizza pizza) {
  write_pizza(pizza);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("pizzalist");
  list.push_back(pizza.get_item_name());
  write_menu_item_list(list, "pizzalist");
}

// create burger
void WriteIn::create_burger(Burger burger) {
  write_burger(burger);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("burgerlist");
  list.push_back(burger.get_item_name());
  write_menu_item_list(list, "burgerlist");
}

// create noodle
void WriteIn::create_noodle(Noodle noodle) {
  write_noodle(noodle);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("noodlelist");
  list.push_back(noodle.get_item_name());
  write_menu_item_list(list, "noodlelist");
}

// create chips
void WriteIn::create_chips(Chips chips) {
  write_chips(chips);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("chipslist");
  list.push_back(chips.get_item_name());
  write_menu_item_list(list, "chips");
}

// create rice
void WriteIn::create_rice(Rice rice) {
  write_rice(rice);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("ricelist");
  list.push_back(rice.get_item_name());
  write_menu_item_list(list, "ricelist");
}

// create drink
void WriteIn::create_drink(Drink drink) {
  write_drink(drink);  // create .txt file
  ReadIn read_in;
  std::vector<string> list = read_in.read_menu_item_list("drinkslist");
  list.push_back(drink.get_item_name());
  write_menu_item_list(list, "drinkslist");
}

// remove menu item
int WriteIn::remove_menu_item(std::string name, std::string item_type) {
  ReadIn read_in;
  std::vector<string>* list = new std::vector<string>(
      read_in.read_menu_item_list(item_type));  // read in the menu item list

  int index = 0;
  bool found_item = false;
  // search thorugh vector and delete first instance with name
  while (index < (*list).size() && found_item == false) {
    if ((*list)[index] == name) {
      (*list).erase((*list).begin() +
                    index);  // remove ingredient at corresponding index
      found_item = true;
    }
    index++;
  }
  // if found, write back to list file and remove the corresponding txt file
  int is_deleted = -1;
  if (found_item == true) {
    is_deleted = 0;
    WriteIn write_in;
    write_in.write_menu_item_list(*list, item_type);
    std::string file_name = name + ".txt";
    remove(file_name.c_str());
  }

  delete list;

  return is_deleted;
}

// create new ingredient
void WriteIn::add_new_ingredient(Ingredient ingredient) {
  ReadIn read_in;

  IngredientList* list = new IngredientList();

  *list = read_in.read_ingredient_list();
  // read in ingredient list

  list->add_ingredient(ingredient);
  write_ingredient_list(*list);

  delete list;
}

// remove pasta
int WriteIn::remove_pasta(std::string name) {
  int is_deleted = remove_menu_item(name, "pastalist");
  return is_deleted;
}

// remove pizza
int WriteIn::remove_pizza(std::string name) {
  int is_deleted = remove_menu_item(name, "pizzalist");
  return is_deleted;
}

// remove burger
int WriteIn::remove_burger(std::string name) {
  int is_deleted = remove_menu_item(name, "burgerlist");
  return is_deleted;
}

// remove noodle
int WriteIn::remove_noodle(std::string name) {
  int is_deleted = remove_menu_item(name, "noodlelist");
  return is_deleted;
}

// remove chips
int WriteIn::remove_chips(std::string name) {
  int is_deleted = remove_menu_item(name, "chipslist");
  return is_deleted;
}

// remove rice
int WriteIn::remove_rice(std::string name) {
  int is_deleted = remove_menu_item(name, "ricelist");
  return is_deleted;
}

// remove drink
int WriteIn::remove_drink(std::string name) {
  int is_deleted = remove_menu_item(name, "drinkslist");
  return is_deleted;
}

// deconstructor
WriteIn::~WriteIn() {}