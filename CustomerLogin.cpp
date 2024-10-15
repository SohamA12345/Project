#include "CustomerLogin.h"

#include "CustomerFoodDrink.h"
#include "MMaker.h"

void CustomerLogin::run(int& state_portal) {
<<<<<<< HEAD
  menu customer;  // A menu object to implement a login portal for manager.
  menu account_created;
  CustomerFoodDrink obj;
  string username;
  string password;
  string read_line;
  int customer_choice = 0;
  int account_created_choice = 0;
  customer.menu_head("Login/Create an account.");
  customer.add("Login", 1, "Login if you already have an account.");
  customer.add("Create an account", 2,
               "If you don't have an account, create using this option.");
  customer.add("Back", 3, "Returns to Manager/Customer options.");
  customer_choice = customer.display();
  bool username_exist = true;
=======
    menu customer;  // A menu object to implement a login portal for manager.
    menu account_created;
    CustomerFoodDrink obj;
    string username;
    string password;
    string read_line;

    int customer_choice = 0;
    int account_created_choice = 0;

    // options for the user (customer)
    customer.menu_head("Login/Create an account.");
    customer.add("Login", 1, "Login if you already have an account.");
    customer.add("Create an account", 2, "If you don't have an account, create using this option.");
    customer.add("Back", 3, "Returns to Manager/Customer options.");
    customer_choice = customer.display();
    bool username_exist = true;
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46

  switch (customer_choice) {
    case 1: {
      cout << "Username: ";
      getline(cin, username);
      bool username_found = false;
      int line_number = 0;

      ifstream i_usernames_file("usernames");
      if (i_usernames_file.is_open()) {
        while (getline(i_usernames_file, read_line)) {
          line_number++;
          if (read_line == username) {
            cout << "Username Exists. Press 'Enter' to continue.";
            cin.get();
            username_found = true;
            break;
          }
        }
        i_usernames_file.close();
      }

      if (!username_found) {
        cout << "Login failed. No matching username found, please create a new "
                "account\n";
        cout << "Press enter to return to previous options.";
        cin.get();
        state_customer_login = 1;
        return;
      }

      cout << "Password: ";
      getline(cin, password);

      ifstream i_passwords_file("passwords");
      if (i_passwords_file.is_open()) {
        for (int i = 0; i < line_number; i++) {
          getline(i_passwords_file,
                  read_line);  // Reads the line in password associated with the
                               // username.
        }
        i_passwords_file.close();
      }

      if (read_line == password) {
        cout << "Login Successful. Press 'Enter' to access the menu.";
        cin.get();
        do {
          obj.run(this->state_customer_login);  // Runs the next interface
                                                // consisting of menu.
        } while (obj.get_state_customer() == 1);
        return;
      } else {
        cout << "Login failed. No matching password found, please create a new "
                "account\n";
        cout << "Press enter to return to previous options.";
        cin.get();
        state_customer_login = 1;
        return;
      }
      break;
    }

    case 2: {
      cout << "Username: ";
      getline(cin, username);

      while (username_exist) {
        username_exist = false;
        ifstream i_usernames_file("usernames");
        if (i_usernames_file.is_open()) {
          while (getline(i_usernames_file, read_line)) {
            if (read_line == username) {
              cout << "Username Exists. Enter a new username: ";
              getline(cin, username);
              username_exist = true;
              break;
            }
          }
          i_usernames_file.close();
        }
      }

      ofstream o_usernames_file("usernames", ios::app);
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
      getline(cin, password);

      ofstream o_passwords_file("passwords", ios::app);
      if (o_passwords_file.is_open()) {
        o_passwords_file << password << endl;
        this->state_customer_login = 1;
        account_created.menu_head(username + " thanks for creating an account");
        account_created.add("Back to login", 1,
                            "Please login to access the exclusive menu.");
        account_created_choice = account_created.display();
        switch (account_created_choice) {
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
    }

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