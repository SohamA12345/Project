#include "Drink.h"

// Default Constructor
Drink::Drink() : Drink(1, "N/A", 0.0) {}
// Constructor for a drink, not taking ice/sugar
Drink::Drink(int new_size, string new_name, double new_price) {
  item_size = new_size;
  item_name = new_name;
  item_price_initial = new_price;
  sugar = 0;
  ice = false;
}
// Constructor, taking ice/sugar
Drink::Drink(int new_size, string new_name, double new_price, int new_sugar, bool new_ice) {
  item_size = new_size;
  item_name = new_name;
  item_price_initial = new_price;
  sugar = new_sugar;
  ice = new_ice;
}

// returns the price of the drink, which is based on the item's price and
// increases based on the item's size
double Drink::calculate_item_price() {
  item_price_final = item_price_initial * (1 + 0.25 * (item_size - 1));
  return item_price_final;
}

// Functions for adding and removing sugar
void Drink::add_sugar(int num_spoon) { sugar = sugar + num_spoon; }
void Drink::remove_sugar(int num_spoon) { sugar = sugar - num_spoon; }

// function for changing whether ice is added to the drink or not
void Drink::change_ice() {
  // change ice to false if it is currently yes, and vice versa.
  if (ice == false) {
    ice = true;
  } else if (ice == true) {
    ice = false;
  }
}

// function for getting the current amount of sugar
int Drink::get_sugar() { return sugar; }

// function for showing whether ice has been added currently
bool Drink::show_ice() { return ice; }

  // set ice
  void Drink::set_ice(bool has_ice) {
    this->ice = has_ice;
  }