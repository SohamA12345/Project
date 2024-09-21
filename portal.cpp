#include "portal.h"
#include "mmaker.h"

using namespace std;

void portal::run() {
  menu portal;    // A menu object from menu class to implement a portal.
  menu customer;  // A menu object to implment a login portal for manager.

  string username;
  string password;
  ofstream credentials_file("credentials", ios::app);
  int customer_choice = 0;

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
      cout << "Customer\n";

      customer.menu_head("Login/Create an account");
      customer.add("Login");
      customer.add("Create an account");
      customer.add("Back");

      customer_choice = customer.display();

      switch (customer_choice) {
        case 1:
          cout << "Username: ";
          break;
        case 2:
          cout << "Username: ";
          cin >> username;

          if (credentials_file.is_open()) {
            credentials_file << username << endl;
            credentials_file.close();
            cout << "Username saved\n";
          } else {
            cerr << "Unable to open file.\n";
          }

          cout << "Password: ";
          cin >> password;

          if (credentials_file.is_open()) {
            credentials_file << password << endl;
            credentials_file.close();
            cout << "Password saved\n";
          } else {
            cerr << "Unable to open file.\n";
          }

          break;
        case 3:
          this->state = 1;
          break;
        default:
          break;
      }

      break;
    case 3:
      cout << "Exit\n";
      this->state = 0;
      return;
    default:
      cout << "Invalid selection.\n";
      break;
  }
}

int portal::get_state_portal() {
  return this->state;
}

portal::portal() {}
portal::~portal() {}