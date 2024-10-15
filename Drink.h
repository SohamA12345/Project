#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <string>
using namespace std;
#include "MenuItem.h"

class Drink : public MenuItem {
 private:
  int sugar;
  bool ice;

 public:
  // constructors:
  Drink();
  Drink(int size, string name, double price);
  Drink(int size, string name, double price, int sugar, bool ice);

  // increase/decrease the amount of sugar
  void add_sugar(int num_spoon);
  void remove_sugar(int num_spoon);

  // change whether ice is added
  void change_ice();

  // show current amount of sugar
  int get_sugar();

  // show whether ice is currently being added
  bool show_ice();

  // returns the price of the drink
  double calculate_item_price();
};

#endif