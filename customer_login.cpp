#include "customer_login.h"

#include "mmaker.h"

void customer_login::run() {
  menu customer;  // A menu object to implment a login portal for manager.

  string username;
  string password;

  ofstream credentials_file("credentials", ios::app);

  int customer_choice = 0;

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
      //this->state_portal = 1;
      break;
    default:
      break;
  }
}

int customer_login::get_state_customer_login() { return this->state_customer_login; }
customer_login::customer_login() {}
customer_login::~customer_login() {}