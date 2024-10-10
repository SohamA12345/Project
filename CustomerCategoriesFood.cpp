#include "CustomerCategoriesFood.h"
#include "Pasta.h"
#include "MMaker.h"
#include "ReadIn.h"

void CustomerCategoriesFood::run(int& state_customer) {
  menu CustomerCategoriesFood;

  ReadIn obj;

  string item_strg;
  string ingredient;

  vector<string> pasta_list = obj.read_menu_item_list("pastalist");

  CustomerCategoriesFood.menu_head("Cuisine Types: ");

  for (int i = 0; i < pasta_list.size(); i++) {
    item_strg += pasta_list[i] + ", ";
  }

  CustomerCategoriesFood.add("Pasta", 1, item_strg);

  int choice = CustomerCategoriesFood.display();

  switch (choice) {
    case 1:

    {
      menu Pasta_menu;

      Pasta_menu.menu_head("Different Types of Pasta:");

      for (int i = 0; i < pasta_list.size(); i++) {
        Pasta obj_pasta = obj.read_pasta(pasta_list[i]);

        for (int j = 0; j < obj_pasta.get_ingredient_list().size(); j++) {
          ingredient += obj_pasta.get_ingredient_list()[j].get_name() + ", ";
        }

        Pasta_menu.add(pasta_list[i], i, "Pasta Type: " + obj_pasta.get_pasta_type() + "\t" + "Pasta Sauce: " + "\nPrice: " + to_string(obj_pasta.calculate_item_price()) + "\nIngredients: " + ingredient + "\nSize: " + obj_pasta.get_string_size(obj_pasta.get_item_size()));
      }

      int choice = Pasta_menu.display();

      break;
    }

    default:
      break;
  }
}

int CustomerCategoriesFood::get_state_categories() {
  return this->state_categories;
}

CustomerCategoriesFood::CustomerCategoriesFood() {}
CustomerCategoriesFood::~CustomerCategoriesFood() {}