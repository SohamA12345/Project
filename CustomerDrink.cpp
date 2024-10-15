#include "CustomerDrink.h"

#include <limits>

#include "Drink.h"
#include "MMaker.h"
#include "ReadIn.h"

void CustomerDrink::run(int& state_customer) {
  menu CustomerDrink;

  ReadIn obj;
  string item_strg;

  CustomerDrink.menu_head("Drinks");

  vector<string> drink_list = obj.read_menu_item_list("drinklist");

  string size_str;
  char size;

  for (int i = 0; i < drink_list.size(); i++) {
    item_strg += drink_list[i] + ", ";
  }

  for (int i = 0; i < drink_list.size(); i++) {
    Drink obj_drink = obj.read_drink(drink_list[i]);

    CustomerDrink.add(
        drink_list[i], i + 1,
        "Price: " + to_string(obj_drink.calculate_item_price()) +
            "\nNo. of spoons of sugar (Can be change): " +
            to_string(obj_drink.get_sugar()) + "\nIce (Can be changed): " +
            to_string(obj_drink.show_ice()) + "\nSize (Can be changed): " +
            obj_drink.get_string_size(obj_drink.get_item_size()));
  }

  CustomerDrink.add("Back", -1, "Returns to differnt food categories page.");

  int choice = CustomerDrink.display();

  if (choice == -1) {
    state_customer = 1;
    this->state_drink = 0;
    return;
  }

  if (choice > 0) {
    Drink obj_drink = obj.read_drink(drink_list[choice - 1]);

    system("clear");

    while (true) {
      cout << "Size (S for small, M for medium, L for large): ";
      cin >> size;

      if (size == 'S') {
        size_str = "small";
        break;
      } else if (size == 'M') {
        size_str = "medium";
        break;
      } else if (size == 'L') {
        size_str = "large";
        break;
      } else {
        cout << "Invalid input. Please enter a valid charecter for size.\n";
      }
    }

    obj_drink.set_item_size(size_str);

    int sugar_scoops;

    while (true) {
      cout << "No. of spoon of sugar: ";
      cin >> sugar_scoops;

      if (cin.fail()) {
        cin.clear();  // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // ignore invalid input
        cout << "Invalid input. Please enter a numeric value for the "
                "spoons of sugar.\n";
      } else {
        break;  // valid input
      }
    }

    obj_drink.add_sugar(sugar_scoops - obj_drink.get_sugar());

    system("clear");

    bool ice;

    while (true) {
      cout << "Ice (yes then type 1/no then type 0): ";
      cin >> ice;

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

    if (obj_drink.show_ice() != ice) {
      obj_drink.change_ice();
    }

    cout << "Successfully costomised the order. Add to Cart(y/n): ";

    string add_to_cart;
    getline(cin, add_to_cart);

    if (add_to_cart == "y") {
      CustomerFoodDrink::cart_drink.push_back(obj_drink);
      cout << "Succesfully Added to the cart: " << obj_drink.get_item_name()
           << "\t$" << obj_drink.calculate_item_price()
           << "\tPress ENTER to continue";
      cin.get();
    } else if (add_to_cart == "n") {
      // Code continue to close the menu gui.
    } else {
      cout << "Invalid input. Press ENTER to continue.";
      cin.get();
      this->state_drink = 1;
      return;
    }

    state_customer = 1;
    return;
  }
}

int CustomerDrink::get_state_drink() { return this->state_drink; }

CustomerDrink::CustomerDrink(/* args */) {}
CustomerDrink::~CustomerDrink() {}