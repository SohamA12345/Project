#include "CustomerCategoriesFood.h"
#include "AddToCart.h"
#include "Burger.h"
#include "Chips.h"
#include "Ingredient.h"
#include "IngredientList.h"
#include "MMaker.h"
#include "Noodle.h"
#include "Pasta.h"
#include "Pizza.h"
#include "ReadIn.h"
#include "Rice.h"

void CustomerCategoriesFood::run(int& state_customer) {
  menu CustomerCategoriesFood;

  CustomerCategoriesFood.menu_head("Cuisine Types: ");

  ReadIn obj;

  vector<string> item_strg(6);
  string ingredient;

  vector<string> pasta_list = obj.read_menu_item_list("pastalist");
  vector<string> burger_list = obj.read_menu_item_list("burgerlist");
  vector<string> chips_list = obj.read_menu_item_list("chipslist");
  vector<string> noodle_list = obj.read_menu_item_list("noodlelist");
  vector<string> pizza_list = obj.read_menu_item_list("pizzalist");
  vector<string> rice_list = obj.read_menu_item_list("ricelist");

  vector<vector<string>> all_lists = {pasta_list,  burger_list, chips_list,
                                      noodle_list, pizza_list,  rice_list};

  for (int j = 0; j < all_lists.size(); j++) {
    for (int i = 0; i < all_lists[j].size(); i++) {
      item_strg[j] += all_lists[j][i] + ", ";
    }
  }

  CustomerCategoriesFood.add("Pasta", 1, item_strg[0]);
  CustomerCategoriesFood.add("Burger", 2, item_strg[1]);
  CustomerCategoriesFood.add("Chips", 3, item_strg[2]);
  CustomerCategoriesFood.add("Noodles", 4, item_strg[3]);
  CustomerCategoriesFood.add("Pizza", 5, item_strg[4]);
  CustomerCategoriesFood.add("Rice", 6, item_strg[5]);
  CustomerCategoriesFood.add("Back", 7, "Returns Food/Drinks");

  int choice = CustomerCategoriesFood.display();

  Ingredient none;

  none.set_name("None");
  none.set_price(0);

  AddToCart cart;

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

        Pasta_menu.add(
            pasta_list[i], i,
            "Pasta Type: " + obj_pasta.get_pasta_type() + "\t" +
                "Pasta Sauce: " + "\nPrice: " +
                to_string(obj_pasta.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_pasta.get_string_size(obj_pasta.get_item_size()));
      }

      int choice = Pasta_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;

        obj_ingredients.add_ingredient(none);

        cout << "Available Ingredients:\t";

        for (int i = 0; i < obj_ingredients.get_ingredient_list().size(); i++) {
          cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
               << obj_ingredients.get_ingredient_list()[i].get_price() << ")\t";
        }

        cout << endl;

        cout << "Add ingredient? (Type the exactly shown in list above): \n";

        string chosen_ingredient;
        int k = 0;
        bool ingredient_found = false;

        cin >> chosen_ingredient;

        while (true) {
          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               ++i) {
            if (chosen_ingredient ==
                obj_ingredients.get_ingredient_list()[i].get_name()) {
              ingredient_found = true;
              k = i;
              break;
            }
          }

          if (ingredient_found) {
            cout << "Ingredient added: " << chosen_ingredient << endl;
            break;
          } else {
            cout << "Doesn't match any ingredients. Try Again: ";
            cin >> chosen_ingredient;
          }
        }

        Pasta obj_pasta = obj.read_pasta(pasta_list[choice - 1]);
        obj_pasta.add_ingredient(obj_ingredients.get_ingredient_list()[k]);

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        cout << "Available Ingredients:\t";

        for (int i = 0; i < obj_pasta.get_ingredient_list().size(); i++) {
          cout << obj_pasta.get_ingredient_list()[i].get_name() << " $("
               << obj_pasta.get_ingredient_list()[i].get_price() << ")\t";
        }

        cout << endl;

        cout << "Remove ingredient? (Type the exactly shown in list above): "
                "\n";

        string chosen_ingredient_removal;
        int j = 0;
        bool ingredient_removed = false;

        cin >> chosen_ingredient_removal;

        while (true) {
          for (int i = 0; i < obj_pasta.get_ingredient_list().size(); ++i) {
            if (chosen_ingredient_removal ==
                obj_pasta.get_ingredient_list()[i].get_name()) {
              ingredient_removed = true;
              j = i;
              break;
            }
          }

          if (ingredient_removed) {
            cout << "Ingredient removed: " << chosen_ingredient << j << endl;
            break;
          } else {
            cout << "Doesn't match any ingredients. Try Again: ";
            cin >> chosen_ingredient;
          }
        }

        obj_pasta.remove_ingredient(j);

        if (j < obj_pasta.get_ingredient_list().size()) {
        } else {
          cout << "Invalid ingredient index. Unable to remove." << endl;
        }

        // Display remaining ingredients in obj_ingredients
        cout << "Updated Ingredients:\t";
        for (int i = 0; i < obj_pasta.get_ingredient_list().size(); i++) {
          cout << obj_pasta.get_ingredient_list()[i].get_name() << " $("
               << obj_pasta.get_ingredient_list()[i].get_price() << ")\t";
        }
        cout << endl;

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        cin >> add_to_cart;

        if (add_to_cart == "y") {
          cart.run(state_customer, obj_pasta);
        } else if (add_to_cart == "n") {
          // Code continue to close the menu gui.
        } else {
          cout << "Invalid input. Press ENTER to continue.";
          cin.get();
          this->state_categories = 1;
          return;
        }

        state_customer = 1;
        return;
      }

      break;
    }
    case 2:

    {
    }

    break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:

      this->state_categories = 0;
      state_customer = 1;

      return;
    default:
      break;
  }
}

int CustomerCategoriesFood::get_state_categories() {
  return this->state_categories;
}

CustomerCategoriesFood::CustomerCategoriesFood() {}
CustomerCategoriesFood::~CustomerCategoriesFood() {}