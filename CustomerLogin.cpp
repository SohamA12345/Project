#include "CustomerLogin.h"
#include "CustomerFoodDrink.h"
#include "MMaker.h"

void CustomerLogin::run(int& state_portal) {
  menu customer;  // A menu object to implment a login portal for manager.
  menu acount_created;

  CustomerFoodDrink obj;

  string username;
  string password;
  string read_line;

  ofstream o_usernames_file("usernames", ios::app);
  ifstream i_usernames_file("usernames");

  ofstream o_passwords_file("passwords", ios::app);
  ifstream i_passwords_file("passwords");

  int customer_choice = 0;
  int acount_created_choice = 0;

  customer.menu_head("Login/Create an account.");
  customer.add("Login", 1, "Login if you already have an account.");
  customer.add("Create an account", 2,
               "If you don't have an account, create using this option.");
  customer.add("Back", 3, "Returns to Manager/Customer options.");

  customer_choice = customer.display();

  switch (customer_choice) {
    case 1:
      cout << "Username: ";
      getline(cin, username);
      bool username_found;
      int line_number;
      username_found = false;
      line_number = 0;

      if (i_usernames_file.is_open()) {
        while (getline(i_usernames_file, read_line)) {
          line_number++;

          if (read_line == username) {
            cout << "Username Exists. Press 'Enter' to continue.";
            cin.get();

            i_usernames_file.close();
            this->state_customer_login = 0;

            username_found = true;

            break;
          }
        }
      }

      if (username_found == false) {
        cout << "Login failed. No matching username found, please create a "
                "new "
                "acount\n";
        cout << "Press enter to return to previous options.";

        cin.get();
        state_customer_login = 1;

        return;
      }

      cout << "Password: ";
      getline(cin, password);

      if (i_passwords_file.is_open()) {
        for (int i = 0; i < line_number; i++) { // Reads the line in password associated with the username.
          getline(i_passwords_file, read_line);
        }
      }

      if (read_line == password) {
        cout << "Login Successful. Press 'Enter' to acess the menu.";
        cin.get();

        i_passwords_file.close();
        this->state_customer_login = 0;

        do
        {
          obj.run(this->state_customer_login); // Runs the next interface consisting of menu.
        } while (obj.get_state_customer() == 1);

        return;
      } else {
        cout << "Login failed. No matching password found, please create a "
                "new "
                "acount\n";
        cout << "Press enter to return to previous options.";
        cin.get();
        state_customer_login = 1;
        return;
      }

      break;
    case 2:
      cout << "Username: ";
      cin >> username;

      if (o_usernames_file.is_open()) {
        o_usernames_file << username << endl;
        o_usernames_file.close();
        cout << "Username saved\n";
        this->state_customer_login = 1;
      } else {
        cout << "Unable to open file.\n";
        return;
      }

      cout << "Password: ";
      cin >> password;

      if (o_passwords_file.is_open()) {
        o_passwords_file << password << endl;
        this->state_customer_login = 1;

        acount_created.menu_head(username + " thanks for creating an account");
        acount_created.add("Back to login", 1,
                           "Please login to access the exclusive menu.");

        acount_created_choice = acount_created.display();

        switch (acount_created_choice) {
          case 1:
            cin.get();  // Pauses program till enter is pressed.
            break;
          default:
            break;
        }

        o_passwords_file.close();
      } else {
        cout << "Unable to open file.\n";
        return;
      }

      break;
    case 3:
      state_portal = 1;
      state_customer_login = 0;
      break;
    default:
      break;
  }
}

int CustomerLogin::get_state_customer_login() {
  return this->state_customer_login;
}

CustomerLogin::CustomerLogin() {}
CustomerLogin::~CustomerLogin() {}