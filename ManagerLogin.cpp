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

  // Prompt for username, Ensures when the user presses enter doesn't effect once returned to portal.
  cout << "Manager Username: ";
<<<<<<< HEAD
  getline(cin, username);  // Ensures when the user presses enter doesn't effect
                           // once returned to portal.
=======
  getline(cin, username); 
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46

  // determine if username is matching
  if (this->username == username) {
    cout << "Username matches\n";
  } else {
    cout << "Username does not match. Click enter to return to login portal.\n";
    cin.get();
    state_portal = 1;
    return;
  }

  // Prompt for password, Ensures when the user presses enter doesn't effect once returned to portal.
  cout << "Manager Password: ";
  getline(cin, password);

<<<<<<< HEAD
=======
  // determine if password is matching
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46
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