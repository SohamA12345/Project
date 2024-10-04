#include "ManagerMenu.h"
#include <fstream>
#include "MMaker.h"

void ManagerMenu::run(int& state_portal) {
  menu ManagerMenu;

  ManagerMenu.menu_head("Manager Tools");

  ManagerMenu.add("Create menu items", 1, "Use this to create a new dish/drink/ingredient in the menu.");
  ManagerMenu.add("Show customer's username and password", 2, "Helps if a customer forgot their username or password.");
  ManagerMenu.add("Deletes all customer's username and login details", 3, "No way to recover customer's username or pass once removed.");
  ManagerMenu.add("Log out", 4, "Goes back to the login. Logs out as well.");

  int choice = ManagerMenu.display();
  
  string line1;
  string line2;

  ifstream i_username("usernames");
  const char* username_file = "usernames";

  ifstream i_passwords("passwords");
  const char* password_file = "passwords";

  switch (choice)
  {
    case 1:
      /* code */
      break;
    case 2:
      while(getline(i_username, line1) && getline(i_passwords, line2)) {
        cout << line1 << '\t' << line2 << endl;
      }
      cout << "Press ENTER to continue";
      cin.get();
      this->state_portal_manager = 1;
      break;
    case 3:
      if (remove(username_file) == 0) {
        cout << "File deleted successfully.\n";
      } else {
        cout << "Error deleting file\n";
      }

      if (remove(password_file) == 0) {
        cout << "File deleted successfully.\n";
      } else {
        cout << "Error deleting file\n";
      }

      cout << "Press ENTER to continue";
      cin.get();
      this->state_portal_manager = 1;

      break;
    case 4:
      this->state_portal_manager = 0;
      state_portal = 1;
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