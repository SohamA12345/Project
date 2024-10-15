#include "CategoriesFood.h"

#include <limits>

#include "IngredientList.h"
#include "MMaker.h"
#include "ReadIn.h"
#include "WriteIn.h"

void CategoriesFood::run(int& state_portal_food) {
  menu CategoriesFood;

  ReadIn obj_read;

  IngredientList obj_ingredients = obj_read.read_ingredient_list();

  CategoriesFood.menu_head("What type of food is required to be created?");

  CategoriesFood.add("Pasta", 1, "");
  CategoriesFood.add("Chips", 2, "");
  CategoriesFood.add("Pizza", 3, "");
  CategoriesFood.add("Rice", 4, "");
  CategoriesFood.add("Noodle", 5, "");
  CategoriesFood.add("Burger", 6, "");
  CategoriesFood.add("Back", 7, "Returns to Menu Updating Suite");

  int choice = CategoriesFood.display();

  switch (choice) {
    case 1: {
      system("clear");

      string name;
      double price;
      char size;
      int size_int;
      string type;
      string sauce;

      cout << "Name of pasta: ";

      getline(cin, name);

      while (true) {
        cout << "Price: ";
        cin >> price;

        if (cin.fail()) {
          cin.clear();  // clear the error flag
          cin.ignore(numeric_limits<streamsize>::max(),
                     '\n');  // ignore invalid input
          cout
              << "Invalid input. Please enter a numeric value for the price.\n";
        } else {
          break;  // valid input
        }
      }

      system("clear");

      while (true) {
        cout << "Size (S for small, M for medium, L for large): ";
        cin >> size;

        if (size == 'S') {
          size_int = 1;
          break;
        } else if (size == 'M') {
          size_int = 2;
          break;
        } else if (size == 'L') {
          size_int = 3;
          break;
        } else {
          cout << "Invalid input. Please enter a valid charecter for size.\n";
        }
      }

      system("clear");

      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // ignore any extra \n

      cout << "Enter pasta type: ";
      getline(cin, type);

      system("clear");

      cout << "Enter pasta sauce name: ";
      getline(cin, sauce);

      Pasta obj(name, price, size_int, type, sauce);

      system("clear");

      bool finish_adding;

      while (!finish_adding) {
        cout << "Available new Ingredients:\t";

        for (int i = 0; i < obj_ingredients.get_ingredient_list().size(); i++) {
          cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
               << obj_ingredients.get_ingredient_list()[i].get_price() << ")\t";
        }

        cout << "Currently added Ingredients:\t";

        for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
          cout << obj.get_ingredient_list()[i].get_name() << " $("
               << obj.get_ingredient_list()[i].get_price() << ")\t";
        }

        cout << endl;

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
          obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
        }
      }

      WriteIn obj2;

      obj2.create_pasta(obj);

      cout << "Successfully created an pasta dish. Press ENTER to return.";
      cin.get();

      this->state_categories_food = 1;

      return;

    }

    break;
    case 2:
      // Chips
      {
        system("clear");

        string name;
        double price;
        char size;
        int size_int;
        string cut;
        string seasoning;

        cout << "Name of chips: ";

        getline(cin, name);

        while (true) {
          cout << "Price: ";
          cin >> price;

          if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');  // ignore invalid input
            cout << "Invalid input. Please enter a numeric value for the "
                    "price.\n";
          } else {
            break;  // valid input
          }
        }

        system("clear");

        while (true) {
          cout << "Size (S for small, M for medium, L for large): ";
          cin >> size;

          if (size == 'S') {
            size_int = 1;
            break;
          } else if (size == 'M') {
            size_int = 2;
            break;
          } else if (size == 'L') {
            size_int = 3;
            break;
          } else {
            cout << "Invalid input. Please enter a valid charecter for size.\n";
          }
        }

        system("clear");

        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // ignore any extra \n

        cout << "Enter chip's cut: ";
        getline(cin, cut);

        system("clear");

        cout << "Enter chip's seosoning: ";
        getline(cin, seasoning);

        Chips obj(name, price, size_int, cut, seasoning);

        system("clear");

        bool finish_adding;

        while (!finish_adding) {
          cout << "Available new Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Currently added Ingredients:\t";

          for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
            cout << obj.get_ingredient_list()[i].get_name() << " $("
                 << obj.get_ingredient_list()[i].get_price() << ")\t";
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
            obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        WriteIn obj2;

        obj2.create_chips(obj);

        cout << "Successfully created an pasta dish. Press ENTER to return.";
        cin.get();

        this->state_categories_food = 1;

        return;
      }

      break;
    case 3:
      // Pizza
      {
        system("clear");

        string name;
        double price;
        char size;
        int size_int;
        string sauce;
        string cheese;

        cout << "Name of pizza: ";

        getline(cin, name);

        while (true) {
          cout << "Price: ";
          cin >> price;

          if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');  // ignore invalid input
            cout << "Invalid input. Please enter a numeric value for the "
                    "price.\n";
          } else {
            break;  // valid input
          }
        }

        system("clear");

        while (true) {
          cout << "Size (S for small, M for medium, L for large): ";
          cin >> size;

          if (size == 'S') {
            size_int = 1;
            break;
          } else if (size == 'M') {
            size_int = 2;
            break;
          } else if (size == 'L') {
            size_int = 3;
            break;
          } else {
            cout << "Invalid input. Please enter a valid charecter for size.\n";
          }
        }

        system("clear");

        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // ignore any extra \n

        cout << "Enter pizza's sauce: ";
        getline(cin, sauce);

        system("clear");

        cout << "Enter pizza's cheese: ";
        getline(cin, cheese);

        Pizza obj(name, price, size_int, sauce, cheese);

        system("clear");

        bool finish_adding;

        while (!finish_adding) {
          cout << "Available new Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Currently added Ingredients:\t";

          for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
            cout << obj.get_ingredient_list()[i].get_name() << " $("
                 << obj.get_ingredient_list()[i].get_price() << ")\t";
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
            obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        WriteIn obj2;

        obj2.create_pizza(obj);

        cout << "Successfully created an pasta dish. Press ENTER to return.";
        cin.get();

        this->state_categories_food = 1;

        return;
      }

      break;
    case 4:
      // Rice
            {
        system("clear");

        string name;
        double price;
        char size;
        int size_int;
        string type;

        cout << "Name of rice: ";

        getline(cin, name);

        while (true) {
          cout << "Price: ";
          cin >> price;

          if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');  // ignore invalid input
            cout << "Invalid input. Please enter a numeric value for the "
                    "price.\n";
          } else {
            break;  // valid input
          }
        }

        system("clear");

        while (true) {
          cout << "Size (S for small, M for medium, L for large): ";
          cin >> size;

          if (size == 'S') {
            size_int = 1;
            break;
          } else if (size == 'M') {
            size_int = 2;
            break;
          } else if (size == 'L') {
            size_int = 3;
            break;
          } else {
            cout << "Invalid input. Please enter a valid charecter for size.\n";
          }
        }

        system("clear");

        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // ignore any extra \n

        cout << "Enter rice type: ";
        getline(cin, type);

        Rice obj(name, price, size_int, type);

        system("clear");

        bool finish_adding;

        while (!finish_adding) {
          cout << "Available new Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Currently added Ingredients:\t";

          for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
            cout << obj.get_ingredient_list()[i].get_name() << " $("
                 << obj.get_ingredient_list()[i].get_price() << ")\t";
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
            obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        WriteIn obj2;

        obj2.create_rice(obj);

        cout << "Successfully created an pasta dish. Press ENTER to return.";
        cin.get();

        this->state_categories_food = 1;

        return;
      }

      break;
    case 5:
      // Noodle
            {
        system("clear");

        string name;
        double price;
        char size;
        int size_int;
        string type;
        string soup;

        cout << "Name of noodle: ";

        getline(cin, name);

        while (true) {
          cout << "Price: ";
          cin >> price;

          if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');  // ignore invalid input
            cout << "Invalid input. Please enter a numeric value for the "
                    "price.\n";
          } else {
            break;  // valid input
          }
        }

        system("clear");

        while (true) {
          cout << "Size (S for small, M for medium, L for large): ";
          cin >> size;

          if (size == 'S') {
            size_int = 1;
            break;
          } else if (size == 'M') {
            size_int = 2;
            break;
          } else if (size == 'L') {
            size_int = 3;
            break;
          } else {
            cout << "Invalid input. Please enter a valid charecter for size.\n";
          }
        }

        system("clear");

        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // ignore any extra \n

        cout << "Enter noodle's type: ";
        getline(cin, type);

        system("clear");

        cout << "Enter noodle's soup: ";
        getline(cin, soup);

        Noodle obj(name, price, size_int, type, soup);

        system("clear");

        bool finish_adding;

        while (!finish_adding) {
          cout << "Available new Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Currently added Ingredients:\t";

          for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
            cout << obj.get_ingredient_list()[i].get_name() << " $("
                 << obj.get_ingredient_list()[i].get_price() << ")\t";
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
            obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        WriteIn obj2;

        obj2.create_noodle(obj);

        cout << "Successfully created an pasta dish. Press ENTER to return.";
        cin.get();

        this->state_categories_food = 1;

        return;
      }

      break;
    case 6:
      // Burger
            {
        system("clear");

        string name;
        double price;
        char size;
        int size_int;
        string bun;
        string meat;

        cout << "Name of burger: ";

        getline(cin, name);

        while (true) {
          cout << "Price: ";
          cin >> price;

          if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');  // ignore invalid input
            cout << "Invalid input. Please enter a numeric value for the "
                    "price.\n";
          } else {
            break;  // valid input
          }
        }

        system("clear");

        while (true) {
          cout << "Size (S for small, M for medium, L for large): ";
          cin >> size;

          if (size == 'S') {
            size_int = 1;
            break;
          } else if (size == 'M') {
            size_int = 2;
            break;
          } else if (size == 'L') {
            size_int = 3;
            break;
          } else {
            cout << "Invalid input. Please enter a valid charecter for size.\n";
          }
        }

        system("clear");

        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // ignore any extra \n

        cout << "Enter burger's bun: ";
        getline(cin, bun);

        system("clear");

        cout << "Enter burger's meat: ";
        getline(cin, meat);

        Burger obj(name, price, size_int, bun, meat);

        system("clear");

        bool finish_adding;

        while (!finish_adding) {
          cout << "Available new Ingredients:\t";

          for (int i = 0; i < obj_ingredients.get_ingredient_list().size();
               i++) {
            cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
                 << obj_ingredients.get_ingredient_list()[i].get_price()
                 << ")\t";
          }

          cout << endl;

          cout << "Currently added Ingredients:\t";

          for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
            cout << obj.get_ingredient_list()[i].get_name() << " $("
                 << obj.get_ingredient_list()[i].get_price() << ")\t";
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
            obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
          }
        }

        WriteIn obj2;

        obj2.create_burger(obj);

        cout << "Successfully created an pasta dish. Press ENTER to return.";
        cin.get();

        this->state_categories_food = 1;

        return;
      }

      break;
    case 7:
      this->state_categories_food = 0;
      state_portal_food = 1;

      return;
    default:
      break;
  }
}

int CategoriesFood::get_state_categories_food() {
  return this->state_categories_food;
}

CategoriesFood::CategoriesFood() {}
CategoriesFood::~CategoriesFood() {}