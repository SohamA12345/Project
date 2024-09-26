#include "drink.h"

// Constructors for a drink. 
drink::drink(int new_size, string new_name, double new_price) {
    item_size = new_size;
    item_name = new_name;
    item_price = new_price;
}
drink::drink() {
    item_size = 1;
    item_name = "N/A";
    item_price = 0.0;
}

// returns the price of the drink, which is based on the item's price and increases based on the item's size
double drink::calculate_item_price() {
    drink_price = item_price * (1 + 0.25 * (item_size - 1));
    return drink_price;
}