#include "MenuItem.h"

// Default menu_item constructor
MenuItem::MenuItem() {
  item_name = "N/A";
  item_price_initial = 0;
  item_size = 1;
}

// Menu_item constructor
MenuItem::MenuItem(string name, double price, int size) {
  item_name = name;
  item_price_initial = price;
  item_size = size;
  if (item_size > 3) {
    item_size = 3;
  } else if (item_size < 1) {
    item_size = 1;
  }
}

// Setter functions that changes the variables for the menu item
void MenuItem::set_item_name(string name) {
  item_name = name;
  // cout << "This item's name is changed to " << item_name << endl;
}
void MenuItem::set_item_price(double price) {
  item_price_initial = price;
  // cout << "This item's price is changed to " << item_price_initial << endl;
}
void MenuItem::set_item_size(string str_size) {
  if (str_size == "small") {
    item_size = 1;
  } else if (str_size == "medium") {
    item_size = 2;
  } else if (str_size == "large") {
    item_size = 3;
  } else {
    cout << "invalid input, size set to small" << endl;
    item_size = 1;
  }
  // cout << "This item's size is changed to " << item_size << endl;
}

// Getter functions that outputs the values of the menu item
string MenuItem::get_item_name() { return item_name; }
double MenuItem::get_item_price() { return item_price_initial; }
int MenuItem::get_item_size() { return item_size; }

string MenuItem::get_string_size(int int_size) {
  string item_size;
  if (int_size == 1) {
    item_size = "small";
  } else if (int_size == 2) {
    item_size = "medium";
  } else if (int_size == 3) {
    item_size = "large";
  } else {
    item_size = "small";
  }
  return item_size;
}