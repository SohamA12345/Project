#include "Drink.h"

// Constructors for a drink.
Drink::Drink(int new_size, string new_name, double new_price) {
  item_size = new_size;
  item_name = new_name;
  item_price_initial = new_price;
  sugar = 0;
  ice = false;
}
// Default Constructor
Drink::Drink() : Drink(1, "N/A", 0.0) {}

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