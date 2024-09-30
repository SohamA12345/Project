#include "manager_login.h"
#include "manager_menu.h"
#include <iostream>

using namespace std;

void manager_login::run(int& state_portal) {
  string username;
  string password;

  //manager_menu obj;

  cout << "Manager Username: ";
  getline(cin, username); // Ensures when the user presses enter doesn't effect once returned to portal.

  if (this->username == username) {
    cout << "Username matches\n";
  } else {
    cout << "Username does not match. Click enter to return to login portal.\n";
    cin.get();
    state_portal = 1;
    return;
  }

  cout << "Manager Password: ";
  getline(cin, password);
  
  if (this->password == password) {
    cout << "Login Successful\n";

    // do
    // {
    //   obj.run();
    // } while (obj.get_state_portal_manager() == 1);

  } else {
    cout << "Password does not match. Click enter to return to login portal.\n";
    cin.get();
    state_portal = 1;
    return;
  }
}

manager_login::manager_login() {}
manager_login::~manager_login() {}