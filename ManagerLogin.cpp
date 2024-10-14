#include "ManagerLogin.h"

#include <termios.h>
#include <unistd.h>

#include <iostream>

#include "ManagerMenu.h"

using namespace std;

void ManagerLogin::run(int& state_portal) {
  string username;
  string password;

  ManagerMenu obj;

  cout << "Manager Username: ";
  getline(cin, username);  // Ensures when the user presses enter doesn't effect
                           // once returned to portal.

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

    do {
      obj.run(state_portal);
    } while (obj.get_state_portal_manager() == 1);

  } else {
    cout << "Password does not match. Click enter to return to login portal.\n";
    cin.get();
    state_portal = 1;
    return;
  }
}

ManagerLogin::ManagerLogin() {}
ManagerLogin::~ManagerLogin() {}