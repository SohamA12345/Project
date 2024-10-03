#include "Portal.h"
#include "CustomerLogin.h"
#include "ManagerLogin.h"
#include "MMaker.h"

using namespace std;

void Portal::run() {
  menu Portal; // A menu object from menu class to implement a Portal.
  CustomerLogin obj; //runs the customer login.
  ManagerLogin obj_manager; //runs manager login.

  Portal.menu_head("Portal");

  Portal.add("Manager", 1, "Manager Portal only for branch manager.");
  Portal.add("Customer", 2, "Dear customer, please login to start the order. If this is the first time visiting, create an account.");
  Portal.add("Exit", 3, "Thanks for visiting");

  int portal_choice = Portal.display();

  switch (portal_choice) {
    case 1:
      obj_manager.run(this->state_portal);
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

int Portal::get_state_portal() {
  return this->state_portal;
}

Portal::Portal() {}
Portal::~Portal() {}