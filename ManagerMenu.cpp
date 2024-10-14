#include "ManagerMenu.h"
#include <fstream>
#include "MMaker.h"
#include "FoodDrink.h"

void ManagerMenu::run(int& state_portal) {
  // create ManagerMenu, of class menu, which has tools 'create menu items', 'show customer username + password',
  // 'delete all customer details', 'log out'. Each tool/method has their own description
  menu ManagerMenu;

  ManagerMenu.menu_head("Manager Tools");

  ManagerMenu.add("Create menu items", 1, "Use this to create a new dish/drink/ingredient in the menu.");
  ManagerMenu.add("Show customer's username and password", 2, "Helps if a customer forgot their username or password.");
  ManagerMenu.add("Deletes all customer's username and login details", 3, "No way to recover customer's username or pass once removed.");
  ManagerMenu.add("Log out", 4, "Goes back to the login. Logs out as well.");

  // 
  int choice = ManagerMenu.display();
  
  string line1;
  string line2;

  ifstream i_username("usernames");
  const char* username_file = "usernames";

  ifstream i_passwords("passwords");
  const char* password_file = "passwords";

  FoodDrink obj;

  switch (choice)
  {
    case 1:
      do
      {
        obj.run(this->state_portal_manager);
      } while (obj.get_state_portal_food() == 1);
      
      break;
    case 2:
      // if choosing to display all customer details
      while(getline(i_username, line1) && getline(i_passwords, line2)) {
        cout << line1 << '\t' << line2 << endl;
      }
      cout << "Press ENTER to continue";
      cin.get();
      this->state_portal_manager = 1;

      break;
    case 3:
      // if choosing to delete all customer details
      if (remove(username_file) == 0) {
        cout << "Username file deleted successfully.\n";
      } else {
        cout << "Error deleting username file. File already deleted\n";
      }

      if (remove(password_file) == 0) {
        cout << "Password file deleted successfully.\n";
      } else {
        cout << "Error deleting password file. File already deleted\n";
      }

      cout << "Press ENTER to continue";
      cin.get();
      this->state_portal_manager = 1;

      break;
    case 4:
      // goes back to the stage before (i.e. can choose manager/customer)
      this->state_portal_manager = 0;
      state_portal = 1;
      
      return;
    default:
      break;
  }
}

// returns the state of portal manager, 1 if running, 0 if not. 
int ManagerMenu::get_state_portal_manager() {
  return this->state_portal_manager;
}

ManagerMenu::ManagerMenu() {}
ManagerMenu::~ManagerMenu() {}