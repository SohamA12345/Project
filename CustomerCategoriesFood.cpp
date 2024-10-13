#include "CustomerCategoriesFood.h"

#include <cstdlib>

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
#include "WriteIn.h"

void CustomerCategoriesFood::run(int& state_customer) {
  menu CustomerCategoriesFood;

  CustomerCategoriesFood.menu_head("Cuisine Types: ");

  ReadIn obj;

  vector<string> item_strg(6);

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

  switch (choice) {
    case 1:

    {
      menu Pasta_menu;

      Pasta_menu.menu_head("Different Types of Pasta:");

      for (int i = 0; i < pasta_list.size(); i++) {
        Pasta obj_pasta = obj.read_pasta(pasta_list[i]);

        string ingredient;

        for (int j = 0; j < obj_pasta.get_ingredient_list().size(); j++) {
          ingredient += obj_pasta.get_ingredient_list()[j].get_name() + ", ";
        }

        Pasta_menu.add(
            pasta_list[i], i,
            "Pasta Type: " + obj_pasta.get_pasta_type() + " | " +
                "Pasta Sauce: " + obj_pasta.get_pasta_sauce() +
                "\nPrice: " + to_string(obj_pasta.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_pasta.get_string_size(obj_pasta.get_item_size()));
      }

      int choice = Pasta_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;
        Pasta obj_pasta = obj.read_pasta(pasta_list[choice - 1]);

        system("clear");

        bool finish_adding = false;

        while (!finish_adding) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Add ingredient? (Type the exactly shown in list above or "
                  "'done' to stop adding ingredients): \n";

          string chosen_ingredient;
          int k = 0;
          bool ingredient_found = false;

          getline(cin, chosen_ingredient);

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
            } else if (chosen_ingredient == "done") {
              k = -1;
              finish_adding = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Caution it is "
                      "case-sensitive. Try Again: ";
              getline(cin, chosen_ingredient);
            }
          }

          if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
            obj_pasta.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        system("clear");

        bool finish_removing = false;

        while (!finish_removing) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_pasta.get_ingredient_list().size(); i++) {
            cout << obj_pasta.get_ingredient_list()[i].get_name() << " $("
                 << obj_pasta.get_ingredient_list()[i].get_price() << ")\t";
          }

          cout << endl;

          cout << "Remove ingredient? (Type the exactly shown in list above or "
                  "'done' to stop removing ingredients)): "
                  "\n";

          string chosen_ingredient_removal;
          int j = 0;
          bool ingredient_removed = false;

          getline(cin, chosen_ingredient_removal);

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
              cout << "Ingredient removed: " << chosen_ingredient_removal
                   << endl;
              break;
            } else if (chosen_ingredient_removal == "done") {
              j = -1;
              finish_removing = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Try Again: ";
              getline(cin, chosen_ingredient_removal);
            }
          }

          if (j >= 0) {
            obj_pasta.remove_ingredient(j);
          }
        }

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        getline(cin, add_to_cart);

        if (add_to_cart == "y") {
          CustomerFoodDrink::cart.push_back(obj_pasta);
          cout << "Succesfully Added to the cart: " << obj_pasta.get_item_name()
               << "\t$" << obj_pasta.calculate_item_price()
               << "\tPress ENTER to continue";
          cin.get();
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
      menu Burger_menu;

      Burger_menu.menu_head("Different Types of Burgers:");

      for (int i = 0; i < burger_list.size(); i++) {
        Burger obj_burger = obj.read_burger(burger_list[i]);

        string ingredient;

        for (int j = 0; j < obj_burger.get_ingredient_list().size(); j++) {
          ingredient += obj_burger.get_ingredient_list()[j].get_name() + ", ";
        }

        Burger_menu.add(
            burger_list[i], i,
            "Burger Bun: " + obj_burger.get_burger_bun() + " | " +
                "Burger meat: " + obj_burger.get_burger_meat() +
                "\nPrice: " + to_string(obj_burger.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_burger.get_string_size(obj_burger.get_item_size()));
      }

      int choice = Burger_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;
        Burger obj_burger = obj.read_burger(burger_list[choice - 1]);

        system("clear");

        bool finish_adding = false;

        while (!finish_adding) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Add ingredient? (Type the exactly shown in list above or "
                  "'done' to stop adding ingredients): \n";

          string chosen_ingredient;
          int k = 0;
          bool ingredient_found = false;

          getline(cin, chosen_ingredient);

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
            } else if (chosen_ingredient == "done") {
              k = -1;
              finish_adding = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Caution it is "
                      "case-sensitive. Try Again: ";
              getline(cin, chosen_ingredient);
            }
          }

          if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
            obj_burger.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        system("clear");

        bool finish_removing = false;

        while (!finish_removing) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_burger.get_ingredient_list().size(); i++) {
            cout << obj_burger.get_ingredient_list()[i].get_name() << " $("
                 << obj_burger.get_ingredient_list()[i].get_price() << ")\t";
          }

          cout << endl;

          cout << "Remove ingredient? (Type the exactly shown in list above or "
                  "'done' to stop removing ingredients)): "
                  "\n";

          string chosen_ingredient_removal;
          int j = 0;
          bool ingredient_removed = false;

          getline(cin, chosen_ingredient_removal);

          while (true) {
            for (int i = 0; i < obj_burger.get_ingredient_list().size(); ++i) {
              if (chosen_ingredient_removal ==
                  obj_burger.get_ingredient_list()[i].get_name()) {
                ingredient_removed = true;
                j = i;
                break;
              }
            }

            if (ingredient_removed) {
              cout << "Ingredient removed: " << chosen_ingredient_removal
                   << endl;
              break;
            } else if (chosen_ingredient_removal == "done") {
              j = -1;
              finish_removing = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Try Again: ";
              getline(cin, chosen_ingredient_removal);
            }
          }

          if (j >= 0) {
            obj_burger.remove_ingredient(j);
          }
        }

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        getline(cin, add_to_cart);

        if (add_to_cart == "y") {
          CustomerFoodDrink::cart.push_back(obj_burger);
          cout << "Succesfully Added to the cart: "
               << obj_burger.get_item_name() << "\t$"
               << obj_burger.calculate_item_price()
               << "\tPress ENTER to continue";
          cin.get();
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

    case 3:

    {
      menu Chips_menu;

      Chips_menu.menu_head("Different Types of Chips:");

      for (int i = 0; i < chips_list.size(); i++) {
        Chips obj_chips = obj.read_chips(chips_list[i]);

        string ingredient;

        for (int j = 0; j < obj_chips.get_ingredient_list().size(); j++) {
          ingredient += obj_chips.get_ingredient_list()[j].get_name() + ", ";
        }

        Chips_menu.add(
            chips_list[i], i,
            "Chips cut: " + obj_chips.get_chips_cut() + " | " +
                "Chips seosoning: " + obj_chips.get_chips_seasoning() +
                "\nPrice: " + to_string(obj_chips.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_chips.get_string_size(obj_chips.get_item_size()));
      }

      int choice = Chips_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;
        Chips obj_chip = obj.read_chips(chips_list[choice - 1]);

        system("clear");

        bool finish_adding = false;

        while (!finish_adding) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Add ingredient? (Type the exactly shown in list above or "
                  "'done' to stop adding ingredients): \n";

          string chosen_ingredient;
          int k = 0;
          bool ingredient_found = false;

          getline(cin, chosen_ingredient);

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
            } else if (chosen_ingredient == "done") {
              k = -1;
              finish_adding = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Caution it is "
                      "case-sensitive. Try Again: ";
              getline(cin, chosen_ingredient);
            }
          }

          if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
            obj_chip.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        system("clear");

        bool finish_removing = false;

        while (!finish_removing) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_chip.get_ingredient_list().size(); i++) {
            cout << obj_chip.get_ingredient_list()[i].get_name() << " $("
                 << obj_chip.get_ingredient_list()[i].get_price() << ")\t";
          }

          cout << endl;

          cout << "Remove ingredient? (Type the exactly shown in list above or "
                  "'done' to stop removing ingredients)): "
                  "\n";

          string chosen_ingredient_removal;
          int j = 0;
          bool ingredient_removed = false;

          getline(cin, chosen_ingredient_removal);

          while (true) {
            for (int i = 0; i < obj_chip.get_ingredient_list().size(); ++i) {
              if (chosen_ingredient_removal ==
                  obj_chip.get_ingredient_list()[i].get_name()) {
                ingredient_removed = true;
                j = i;
                break;
              }
            }

            if (ingredient_removed) {
              cout << "Ingredient removed: " << chosen_ingredient_removal
                   << endl;
              break;
            } else if (chosen_ingredient_removal == "done") {
              j = -1;
              finish_removing = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Try Again: ";
              getline(cin, chosen_ingredient_removal);
            }
          }

          if (j >= 0) {
            obj_chip.remove_ingredient(j);
          }
        }

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        getline(cin, add_to_cart);

        if (add_to_cart == "y") {
          CustomerFoodDrink::cart.push_back(obj_chip);
          cout << "Succesfully Added to the cart: "
               << obj_chip.get_item_name() << "\t$"
               << obj_chip.calculate_item_price()
               << "\tPress ENTER to continue";
          cin.get();
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
    
    case 4:

    {
      menu Noodle_menu;

      Noodle_menu.menu_head("Different Types of Chips:");

      for (int i = 0; i < noodle_list.size(); i++) {
        Noodle obj_noodle = obj.read_noodle(noodle_list[i]);

        string ingredient;

        for (int j = 0; j < obj_noodle.get_ingredient_list().size(); j++) {
          ingredient += obj_noodle.get_ingredient_list()[j].get_name() + ", ";
        }

        Noodle_menu.add(
            noodle_list[i], i,
            "Noodle soup: " + obj_noodle.get_noodle_soup() + " | " +
                "Noodle type: " + obj_noodle.get_noodle_type() +
                "\nPrice: " + to_string(obj_noodle.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_noodle.get_string_size(obj_noodle.get_item_size()));
      }

      int choice = Noodle_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;
        Noodle obj_noodle = obj.read_noodle(noodle_list[choice - 1]);

        system("clear");

        bool finish_adding = false;

        while (!finish_adding) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Add ingredient? (Type the exactly shown in list above or "
                  "'done' to stop adding ingredients): \n";

          string chosen_ingredient;
          int k = 0;
          bool ingredient_found = false;

          getline(cin, chosen_ingredient);

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
            } else if (chosen_ingredient == "done") {
              k = -1;
              finish_adding = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Caution it is "
                      "case-sensitive. Try Again: ";
              getline(cin, chosen_ingredient);
            }
          }

          if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
            obj_noodle.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        system("clear");

        bool finish_removing = false;

        while (!finish_removing) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_noodle.get_ingredient_list().size(); i++) {
            cout << obj_noodle.get_ingredient_list()[i].get_name() << " $("
                 << obj_noodle.get_ingredient_list()[i].get_price() << ")\t";
          }

          cout << endl;

          cout << "Remove ingredient? (Type the exactly shown in list above or "
                  "'done' to stop removing ingredients)): "
                  "\n";

          string chosen_ingredient_removal;
          int j = 0;
          bool ingredient_removed = false;

          getline(cin, chosen_ingredient_removal);

          while (true) {
            for (int i = 0; i < obj_burger.get_ingredient_list().size(); ++i) {
              if (chosen_ingredient_removal ==
                  obj_burger.get_ingredient_list()[i].get_name()) {
                ingredient_removed = true;
                j = i;
                break;
              }
            }

            if (ingredient_removed) {
              cout << "Ingredient removed: " << chosen_ingredient_removal
                   << endl;
              break;
            } else if (chosen_ingredient_removal == "done") {
              j = -1;
              finish_removing = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Try Again: ";
              getline(cin, chosen_ingredient_removal);
            }
          }

          if (j >= 0) {
            obj_burger.remove_ingredient(j);
          }
        }

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        getline(cin, add_to_cart);

        if (add_to_cart == "y") {
          CustomerFoodDrink::cart.push_back(obj_burger);
          cout << "Succesfully Added to the cart: "
               << obj_burger.get_item_name() << "\t$"
               << obj_burger.calculate_item_price()
               << "\tPress ENTER to continue";
          cin.get();
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

    case 5:

    {
      menu Pizza_menu;

      Burger_menu.menu_head("Different Types of Burgers:");

      for (int i = 0; i < burger_list.size(); i++) {
        Burger obj_burger = obj.read_burger(burger_list[i]);

        string ingredient;

        for (int j = 0; j < obj_burger.get_ingredient_list().size(); j++) {
          ingredient += obj_burger.get_ingredient_list()[j].get_name() + ", ";
        }

        Burger_menu.add(
            pasta_list[i], i,
            "Burger Bun: " + obj_burger.get_burger_bun() + " | " +
                "Burger meat: " + obj_burger.get_burger_meat() +
                "\nPrice: " + to_string(obj_burger.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_burger.get_string_size(obj_burger.get_item_size()));
      }

      int choice = Burger_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;
        Burger obj_burger = obj.read_burger(pasta_list[choice - 1]);

        system("clear");

        bool finish_adding = false;

        while (!finish_adding) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Add ingredient? (Type the exactly shown in list above or "
                  "'done' to stop adding ingredients): \n";

          string chosen_ingredient;
          int k = 0;
          bool ingredient_found = false;

          getline(cin, chosen_ingredient);

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
            } else if (chosen_ingredient == "done") {
              k = -1;
              finish_adding = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Caution it is "
                      "case-sensitive. Try Again: ";
              getline(cin, chosen_ingredient);
            }
          }

          if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
            obj_burger.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        system("clear");

        bool finish_removing = false;

        while (!finish_removing) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_burger.get_ingredient_list().size(); i++) {
            cout << obj_burger.get_ingredient_list()[i].get_name() << " $("
                 << obj_burger.get_ingredient_list()[i].get_price() << ")\t";
          }

          cout << endl;

          cout << "Remove ingredient? (Type the exactly shown in list above or "
                  "'done' to stop removing ingredients)): "
                  "\n";

          string chosen_ingredient_removal;
          int j = 0;
          bool ingredient_removed = false;

          getline(cin, chosen_ingredient_removal);

          while (true) {
            for (int i = 0; i < obj_burger.get_ingredient_list().size(); ++i) {
              if (chosen_ingredient_removal ==
                  obj_burger.get_ingredient_list()[i].get_name()) {
                ingredient_removed = true;
                j = i;
                break;
              }
            }

            if (ingredient_removed) {
              cout << "Ingredient removed: " << chosen_ingredient_removal
                   << endl;
              break;
            } else if (chosen_ingredient_removal == "done") {
              j = -1;
              finish_removing = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Try Again: ";
              getline(cin, chosen_ingredient_removal);
            }
          }

          if (j >= 0) {
            obj_burger.remove_ingredient(j);
          }
        }

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        getline(cin, add_to_cart);

        if (add_to_cart == "y") {
          CustomerFoodDrink::cart.push_back(obj_burger);
          cout << "Succesfully Added to the cart: "
               << obj_burger.get_item_name() << "\t$"
               << obj_burger.calculate_item_price()
               << "\tPress ENTER to continue";
          cin.get();
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

    case 6:

    {
      menu Rice_menu;

      Burger_menu.menu_head("Different Types of Burgers:");

      for (int i = 0; i < burger_list.size(); i++) {
        Burger obj_burger = obj.read_burger(burger_list[i]);

        string ingredient;

        for (int j = 0; j < obj_burger.get_ingredient_list().size(); j++) {
          ingredient += obj_burger.get_ingredient_list()[j].get_name() + ", ";
        }

        Burger_menu.add(
            pasta_list[i], i,
            "Burger Bun: " + obj_burger.get_burger_bun() + " | " +
                "Burger meat: " + obj_burger.get_burger_meat() +
                "\nPrice: " + to_string(obj_burger.calculate_item_price()) +
                "\nIngredients: " + ingredient + "\nSize: " +
                obj_burger.get_string_size(obj_burger.get_item_size()));
      }

      int choice = Burger_menu.display();

      if (choice > 0) {
        IngredientList obj_ingredients;
        Burger obj_burger = obj.read_burger(pasta_list[choice - 1]);

        system("clear");

        bool finish_adding = false;

        while (!finish_adding) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Add ingredient? (Type the exactly shown in list above or "
                  "'done' to stop adding ingredients): \n";

          string chosen_ingredient;
          int k = 0;
          bool ingredient_found = false;

          getline(cin, chosen_ingredient);

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
            } else if (chosen_ingredient == "done") {
              k = -1;
              finish_adding = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Caution it is "
                      "case-sensitive. Try Again: ";
              getline(cin, chosen_ingredient);
            }
          }

          if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
            obj_burger.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        // Copy the same mechanic as the above code to implement ingredient
        // removal.
        system("clear");

        bool finish_removing = false;

        while (!finish_removing) {
          cout << "Available Ingredients:\t";

          for (int i = 0; i < obj_burger.get_ingredient_list().size(); i++) {
            cout << obj_burger.get_ingredient_list()[i].get_name() << " $("
                 << obj_burger.get_ingredient_list()[i].get_price() << ")\t";
          }

          cout << endl;

          cout << "Remove ingredient? (Type the exactly shown in list above or "
                  "'done' to stop removing ingredients)): "
                  "\n";

          string chosen_ingredient_removal;
          int j = 0;
          bool ingredient_removed = false;

          getline(cin, chosen_ingredient_removal);

          while (true) {
            for (int i = 0; i < obj_burger.get_ingredient_list().size(); ++i) {
              if (chosen_ingredient_removal ==
                  obj_burger.get_ingredient_list()[i].get_name()) {
                ingredient_removed = true;
                j = i;
                break;
              }
            }

            if (ingredient_removed) {
              cout << "Ingredient removed: " << chosen_ingredient_removal
                   << endl;
              break;
            } else if (chosen_ingredient_removal == "done") {
              j = -1;
              finish_removing = true;
              break;
            } else {
              cout << "Doesn't match any ingredients. Try Again: ";
              getline(cin, chosen_ingredient_removal);
            }
          }

          if (j >= 0) {
            obj_burger.remove_ingredient(j);
          }
        }

        cout << "Successfully costomised the order. Add to Cart(y/n): ";

        string add_to_cart;
        getline(cin, add_to_cart);

        if (add_to_cart == "y") {
          CustomerFoodDrink::cart.push_back(obj_burger);
          cout << "Succesfully Added to the cart: "
               << obj_burger.get_item_name() << "\t$"
               << obj_burger.calculate_item_price()
               << "\tPress ENTER to continue";
          cin.get();
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