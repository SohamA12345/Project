#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include "string"

using namespace std;

class manager_login {
 private:
  string username = "Resturant";
  string password = "Menu";
 public:
  void run(int& state_portal);
  manager_login();
  ~manager_login();
};

#endif