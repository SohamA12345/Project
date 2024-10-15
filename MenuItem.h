#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
using namespace std;

class MenuItem {
 protected:
  string item_name;
  double item_price_initial;
  double item_price_final;
  int item_size;

 public:
  // default constructor
  MenuItem();

  // constructor
  MenuItem(string name, double price, int size);

  // setter functions
  void set_item_name(string name);
  void set_item_price(double price);
  void set_item_size(string str_size);

  // getter functions for name, price, size, and size (in string)
  string get_item_name();
  double get_item_price();
  int get_item_size();
  string get_string_size(int int_size);

  // a virtual function for calculating the item price -
  // this will be different based on whether the item is a food or drink
  virtual double calculate_item_price() = 0;
};

#endif