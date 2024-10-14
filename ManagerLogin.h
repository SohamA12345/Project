#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include "string"

using namespace std;

class ManagerLogin {
 private:
  // a default username + password
  string username = "12345";
  string password = "1234";

 public:
  // runs managerlogin
  void run(int& state_portal);

  // default constructor and destructor
  ManagerLogin();
  ~ManagerLogin();
};

#endif