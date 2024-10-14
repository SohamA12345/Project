#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include "string"

using namespace std;

class ManagerLogin {
 private:
  string username = "12345";
  string password = "1234";

 public:
  void run(int& state_portal);
  ManagerLogin();
  ~ManagerLogin();
};

#endif