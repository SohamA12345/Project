#include "CustomerDrink.h"

#include "Drink.h"
#include "MMaker.h"
#include "ReadIn.h"

void CustomerDrink::run(int& state_customer) {
  menu CustomerDrink;

  ReadIn obj;
  string item_strg;

  CustomerDrink.menu_head("Drinks");

  vector<string> drink_list = obj.read_menu_item_list("drinklist");

  for (int i = 0; i < drink_list.size(); i++) {
    item_strg += drink_list[i] + ", ";
  }

  CustomerDrink.add("Drinks", 1, item_strg);
}

int CustomerDrink::get_state_drink() { return this->state_drink; }

CustomerDrink::CustomerDrink(/* args */) {}
CustomerDrink::~CustomerDrink() {}