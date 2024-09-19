#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <iostream>
using namespace std;

class menu_item {
protected:
    string item_name;
    int item_price;
    int item_size;
public:
    menu_item();
    menu_item(string name, int price, int size);
    
    void set_item_name(string name);
    void set_item_price(int price);
    void set_item_size(int size);

    string get_item_name();
    int get_item_price();
    int get_item_size();
};

// Default menu_item constructor
menu_item::menu_item() {
    item_name = "N/A";
    item_price = 0;
    item_size = 1;
}

// Menu_item constructor
menu_item::menu_item(string name, int price, int size) {
    item_name = name;
    item_price = price;
    item_size = size;
}

// Setter functions that changes the variables for the menu item
void menu_item::set_item_name(string name) {
    item_name = name;
    cout << "This item's name is changed to " << item_name << endl;
}
void menu_item::set_item_price(int price) {
    item_price = price;
    cout << "This item's price is changed to " << item_price << endl;
}
void menu_item::set_item_size(int size) {
    item_size = size;
    cout << "This item's size is changed to " << item_size << endl;
}

// Getter functions that outputs the values of the menu item
string menu_item::get_item_name() {
    return item_name;
}
int menu_item::get_item_price() {
    return item_price;
}
int menu_item::get_item_size() {
    return item_size;
}

#endif