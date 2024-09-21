// This implements a menu for the
#include <fstream>
#include <iostream>
#include <string>

#include "mmaker.h"
#include "customer_menu.h"

int main() {
  menu portal;  // A menu object from menu class to implement a portal.
  menu customer; // A menu object to implment a login portal for manager.
	menu manager;

  portal.menu_head("Portal");

  portal.add("customer");
  portal.add("Manager");
  portal.add("Exit");

  int portal_choice = portal.display();

	customer.menu_head("Login/Create an account");

  switch (portal_choice) {
    case 1:
      std::cout << "customer\n";
			int customer_choice = customer.display();
      break;
    case 2:
      std::cout << "Manager\n";
      break;
		case 3:
			std::cout << "Exit\n";
			return 0;
    default:
      std::cout << "Invalid selection.\n";
      break;
  }

	return 0;
}