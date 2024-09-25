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
    // default constructor
    MenuItem();

    // constructor
    MenuItem(string name, double price, int size);
    
    // setter functions
    void set_item_name(string name);
    void set_item_price(double price);
    void set_item_size(int size);

    // getter functions
    string get_item_name();
    double get_item_price();
    int get_item_size();
};



#endif