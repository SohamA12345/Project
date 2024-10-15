#include "FoodDrink.h"

#include <limits>

#include "AddIngredient.h"
#include "CategoriesFood.h"
#include "MMaker.h"
#include "ManagerDrink.h"
#include "WriteIn.h"

void FoodDrink::run(int& state_portal_manager) {
  menu FoodDrink;

  // add ingredient/food/drink to the menu
  FoodDrink.menu_head("Menu Updating Suite");
  FoodDrink.add(
      "Ingredients", 1,
      "Use this to create a ingredient which can be used in new dish.");
  FoodDrink.add("Food", 2,
                "Use ingredient, and various factors to create unique dishes "
                "from a base food type.");
  FoodDrink.add("Drink", 3, "Create a new drink in the menu.");
  FoodDrink.add("Remove a dish", 5, "Remove and already created dish");
  FoodDrink.add("Back", 4, "Return to Manager Tools");

  int choice = FoodDrink.display();

  AddIngredient obj1;
  CategoriesFood obj2;
  ManagerDrink obj3;

  switch (choice) {
    // case 1 goes to add ingredient
    case 1:

      do {
        obj1.run(this->state_portal_food);
      } while (obj1.get_add_ingredient() == 1);

      break;
    // case 2 goes to add food
    case 2:
      do {
        obj2.run(this->state_portal_food);
      } while (obj2.get_state_categories_food() == 1);

      break;
    // case 3 goes to add drink
    case 3:
      do {
        obj3.run(this->state_portal_food);
      } while (obj3.get_state_portal_drink() == 1);

      break;
    // case 4 goes back
    case 4:

      this->state_portal_food = 0;
      state_portal_manager = 1;

      return;
    case 5: {
      system("clear");

      string dish_name;
      WriteIn obj_write;
      ReadIn obj;

      vector<string> pasta_list = obj.read_menu_item_list("pastalist");
      vector<string> burger_list = obj.read_menu_item_list("burgerlist");
      vector<string> chips_list = obj.read_menu_item_list("chipslist");
      vector<string> noodle_list = obj.read_menu_item_list("noodlelist");
      vector<string> pizza_list = obj.read_menu_item_list("pizzalist");
      vector<string> rice_list = obj.read_menu_item_list("ricelist");
      vector<string> drinks_list = obj.read_menu_item_list("drinkslist");

      while (true) {
        cout << "Remove what type of dish (pasta, burger, rice, pizza, "
                "noodles, chips, drinks, done to finish removing): ";
        cin >> dish_name;

        if (dish_name == "pasta") {
          string name;

          for (int i = 0; i < pasta_list.size(); i++) {
            cout << pasta_list[i] << '\t';
          }

          cout << "\nEnter name of the pasta: ";
          cin >> name;

          int returns = obj_write.remove_pasta(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "burger") {
          string name;

          for (int i = 0; i < burger_list.size(); i++) {
            cout << burger_list[i] << '\t';
          }

          cout << "\nEnter name of the burger: ";
          cin >> name;

          int returns = obj_write.remove_burger(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "rice") {
          string name;

          for (int i = 0; i < rice_list.size(); i++) {
            cout << rice_list[i] << '\t';
          }

          cout << "\nEnter name of the rice: ";
          cin >> name;

          int returns = obj_write.remove_rice(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "pizza") {
          string name;

          for (int i = 0; i < pizza_list.size(); i++) {
            cout << pizza_list[i] << '\t';
          }

          cout << "\nEnter name of the pizza: ";
          cin >> name;

          int returns = obj_write.remove_pizza(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "noodles") {
          string name;

          for (int i = 0; i < noodle_list.size(); i++) {
            cout << noodle_list[i] << '\t';
          }

          cout << "\nEnter name of the noodles: ";
          cin >> name;

          int returns = obj_write.remove_noodle(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "chips") {
          string name;

          for (int i = 0; i < chips_list.size(); i++) {
            cout << chips_list[i] << '\t';
          }

          cout << "\nEnter name of the chips: ";
          cin >> name;

          int returns = obj_write.remove_chips(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "drinks") {
          string name;

          for (int i = 0; i < drinks_list.size(); i++) {
            cout << drinks_list[i] << '\t';
          }

          cout << "\nEnter name of the drinks: ";
          cin >> name;

          int returns = obj_write.remove_drink(name);

          if (returns != -1) {
            cout << "Succesfully deleted. Press ENTER to continue.";
            cin.get();
            break;

          } else {
            cout << "Invalid name.";
          }

        } else if (dish_name == "done") {
            break;
        } else {
          cout << "Invalid input. Please enter valid dish name\n";
        }
      }
    }
      this->state_portal_food = 1;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    default:
      break;
  }
}

int FoodDrink::get_state_portal_food() { return this->state_portal_food; }

FoodDrink::FoodDrink() {}
FoodDrink::~FoodDrink() {}