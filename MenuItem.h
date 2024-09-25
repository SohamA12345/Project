#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <iostream>
using namespace std;

class MenuItem {
protected:
    string item_name;
    double item_price;
    int item_size;
public:
    MenuItem();
    MenuItem(string name, double price, int size);
    
    void set_item_name(string name);
    void set_item_price(double price);
    void set_item_size(int size);

    string get_item_name();
    double get_item_price();
    int get_item_size();
};

// Default menu_item constructor
MenuItem::MenuItem() {
    item_name = "N/A";
    item_price = 0;
    item_size = 1;
}

// Menu_item constructor
MenuItem::MenuItem(string name, double price, int size) {
    item_name = name;
    item_price = price;
    item_size = size;
}

// Setter functions that changes the variables for the menu item
void MenuItem::set_item_name(string name) {
    item_name = name;
    cout << "This item's name is changed to " << item_name << endl;
}
void MenuItem::set_item_price(double price) {
    item_price = price;
    cout << "This item's price is changed to " << item_price << endl;
}
void MenuItem::set_item_size(int size) {
    item_size = size;
    cout << "This item's size is changed to " << item_size << endl;
}

// Getter functions that outputs the values of the menu item
string MenuItem::get_item_name() {
    return item_name;
}
double MenuItem::get_item_price() {
    return item_price;
}
int MenuItem::get_item_size() {
    return item_size;
}

#endif