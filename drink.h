#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <string>
using namespace std;
#include "menu_item.h"

class drink : public menu_item {
protected:
    int sugar;
    int ice;
public:
    //constructors: 
    drink(int size, string name, double price);
    drink();

    // returns the price of the drink
    double calculate_item_price();
};

#endif