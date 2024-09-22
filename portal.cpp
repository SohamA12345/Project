#include "portal.h"
#include "customer_login.h"
#include "mmaker.h"

using namespace std;

void portal::run() {
  menu portal; // A menu object from menu class to implement a portal.
  customer_login obj; //runs the customer login.

  menu manager;

  portal.menu_head("Portal");

  portal.add("Manager", 1, "Manager portal only for branch manager.");
  portal.add("Customer", 2, "Dear customer, please login to start the order. If this is the first time visiting, create an account.");
  portal.add("Exit", 3, "Thanks for visiting");

  int portal_choice = portal.display();

  switch (portal_choice) {
    case 1:
    // Manager_menu obj
    // In manager menu it has the ability to delete the username and password files. As well display on the screen.
      break;
    case 2:
    do
    {
      obj.run(state_portal);
    } while (obj.get_state_customer_login() == 1);
  
      break;
    case 3:
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