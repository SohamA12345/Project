#include "portal.h"
#include "customer_login.h"
#include "mmaker.h"

using namespace std;

void portal::run() {
  menu portal; // A menu object from menu class to implement a portal.
  customer_login obj; //runs the customer login.

  menu manager;

  portal.menu_head("Portal");

  portal.add("Manager");
  portal.add("Customer");
  portal.add("Exit");

  int portal_choice = portal.display();

  switch (portal_choice) {
    case 1:
      cout << "Manager\n";
      break;
    case 2:
      obj.run();
      break;
    case 3:
      cout << "Exit\n";
      this->state_portal = 0;
      return;
    default:
      cout << "Invalid selection.\n";
      break;
  }
}

int portal::get_state_portal() {
  return this->state_portal;
}

portal::portal() {}
portal::~portal() {}