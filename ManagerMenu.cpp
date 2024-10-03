#include "ManagerMenu.h"
#include "MMaker.h"

void ManagerMenu::run() {
  menu ManagerMenu;

  ManagerMenu.menu_head("Manager Tools");

  ManagerMenu.add("Create menu items", 1, "Use this to create a new dish/drink/ingredient in the menu.");
  ManagerMenu.add("Show customer's username and password", 2, "Helps if a customer forgot their username or password.");
  ManagerMenu.add("Deletes all customer's username and login details", 3, "No way to recover customer's username or pass once removed.");
  ManagerMenu.add("Back", 4, "Goes back to the login. Logs out as well.");

  int choice = ManagerMenu.display();
  
  switch (choice)
  {
    case 1:
      /* code */
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      this->state_portal_manager = 1;
      return;
    default:
      break;
  }
}

int ManagerMenu::get_state_portal_manager() {
  return this->state_portal_manager;
}

ManagerMenu::ManagerMenu() {}
ManagerMenu::~ManagerMenu() {}