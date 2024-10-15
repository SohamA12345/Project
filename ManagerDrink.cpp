#include "ManagerDrink.h"
#include <limits>
#include "Drink.h"
#include "ManagerMenu.h"

void ManagerDrink::run(int& state_portal_food) {
  // system("clear");

  // string name;
  // double price;
  // char size;
  // int size_int;
  // string cut;
  // string seasoning;

  // cout << "Name of chips: ";

  // getline(cin, name);

  // while (true) {
  //   cout << "Price: ";
  //   cin >> price;

  //   if (cin.fail()) {
  //     cin.clear();  // clear the error flag
  //     cin.ignore(numeric_limits<streamsize>::max(),
  //                '\n');  // ignore invalid input
  //     cout << "Invalid input. Please enter a numeric value for the "
  //             "price.\n";
  //   } else {
  //     break;  // valid input
  //   }
  // }

  // system("clear");

  // while (true) {
  //   cout << "Size (S for small, M for medium, L for large): ";
  //   cin >> size;

  //   if (size == 'S') {
  //     size_int = 1;
  //     break;
  //   } else if (size == 'M') {
  //     size_int = 2;
  //     break;
  //   } else if (size == 'L') {
  //     size_int = 3;
  //     break;
  //   } else {
  //     cout << "Invalid input. Please enter a valid charecter for size.\n";
  //   }
  // }

  // system("clear");

  // cin.ignore(numeric_limits<streamsize>::max(),
  //            '\n');  // ignore any extra \n

  // cout << "Enter chip's cut: ";
  // getline(cin, cut);

  // system("clear");

  // cout << "Enter chip's seosoning: ";
  // getline(cin, seasoning);

  // Chips obj(name, price, size_int, cut, seasoning);

  // system("clear");

  // bool finish_adding;

  // while (!finish_adding) {
  //   cout << "Available new Ingredients:\t";

  //   for (int i = 0; i < obj_ingredients.get_ingredient_list().size(); i++) {
  //     cout << obj_ingredients.get_ingredient_list()[i].get_name() << " $("
  //          << obj_ingredients.get_ingredient_list()[i].get_price() << ")\t";
  //   }

  //   cout << endl;

  //   cout << "Currently added Ingredients:\t";

  //   for (int i = 0; i < obj.get_ingredient_list().size(); i++) {
  //     cout << obj.get_ingredient_list()[i].get_name() << " $("
  //          << obj.get_ingredient_list()[i].get_price() << ")\t";
  //   }

  //   cout << endl;

  //   cout << "Add ingredient? (Type the exactly shown in list above or "
  //           "'done' to stop adding ingredients): \n";

  //   string chosen_ingredient;
  //   int k = 0;
  //   bool ingredient_found = false;

  //   getline(cin, chosen_ingredient);

  //   while (true) {
  //     for (int i = 0; i < obj_ingredients.get_ingredient_list().size(); ++i) {
  //       if (chosen_ingredient ==
  //           obj_ingredients.get_ingredient_list()[i].get_name()) {
  //         ingredient_found = true;
  //         k = i;
  //         break;
  //       }
  //     }

  //     if (ingredient_found) {
  //       cout << "Ingredient added: " << chosen_ingredient << endl;
  //       break;
  //     } else if (chosen_ingredient == "done") {
  //       k = -1;
  //       finish_adding = true;
  //       break;
  //     } else {
  //       cout << "Doesn't match any ingredients. Caution it is "
  //               "case-sensitive. Try Again: ";
  //       getline(cin, chosen_ingredient);
  //     }
  //   }

  //   if (obj_ingredients.get_ingredient_list().size() > 0 && k >= 0) {
  //     obj.add_ingredient(obj_ingredients.get_ingredient_list()[k]);
  //   }
  // }

  // WriteIn obj2;

  // obj2.create_chips(obj);

  // cout << "Successfully created an pasta dish. Press ENTER to return.";
  // cin.get();

  // this->state_categories_food = 1;

  // return;
}

int ManagerDrink::get_state_portal_drink() { return this->state_portal_drink; }

ManagerDrink::ManagerDrink() {}
ManagerDrink::~ManagerDrink() {}