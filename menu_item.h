#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <iostream>
using namespace std;

class menu_item {
protected:
    string item_name;
    double item_price;
    int item_size;
public:
    // default constructor
    menu_item();

    // constructor
    menu_item(string name, double price, int size);
    
    // setter functions
    void set_item_name(string name);
    void set_item_price(double price);
    void set_item_size(int size);

    // getter functions
    string get_item_name();
    double get_item_price();
    int get_item_size();

    // a virtual function for calculating the item price - 
    // this will be different based on whether the item is a food or drink
    virtual double calculate_item_price()=0;
};

#endif