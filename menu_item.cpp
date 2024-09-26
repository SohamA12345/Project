#include "menu_item.h"

// Default menu_item constructor
menu_item::menu_item() {
    item_name = "N/A";
    item_price = 0;
    item_size = 1;
}

// Menu_item constructor
menu_item::menu_item(string name, double price, int size) {
    item_name = name;
    item_price = price;
    item_size = size;
    if (item_size > 3) {
        item_size = 3;
    } else if (item_size < 1) {
        item_size = 1;
    }
}

// Setter functions that changes the variables for the menu item
void menu_item::set_item_name(string name) {
    item_name = name;
    cout << "This item's name is changed to " << item_name << endl;
}
void menu_item::set_item_price(double price) {
    item_price = price;
    cout << "This item's price is changed to " << item_price << endl;
}
void menu_item::set_item_size(int size) {
    item_size = size;
    if (item_size > 3) {
        item_size = 3;
    } else if (item_size < 1) {
        item_size = 1;
    }
    cout << "This item's size is changed to " << item_size << endl;
}

// Getter functions that outputs the values of the menu item
string menu_item::get_item_name() {
    return item_name;
}
double menu_item::get_item_price() {
    return item_price;
}
int menu_item::get_item_size() {
    return item_size;
}
