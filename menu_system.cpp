// This implements a menu for the 
#include "mmaker.h"
#include <iostream>

int main() {

  menu portal; // A menu object from menu class to implement a portal
  menu Customer;

  portal.menu_head("Portal");

  portal.add("Customer");
  portal.add("Manager");
  portal.add("Exit");

  int portal_choice = portal.display();

  Customer.menu_head("Food/Drinks:");

  switch (portal_choice) {
    case 1:
        std::cout << "You selected Italian cuisine.\n";
        break;
    case 2:
        std::cout << "You selected Indian cuisine.\n";
        break;
    default:
        std::cout << "Invalid selection.\n";
        break;
}
}