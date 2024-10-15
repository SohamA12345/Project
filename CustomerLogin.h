#ifndef CUSTOMER_LOGIN_H
#define CUSTOMER_LOGIN_H

#include "FoodItem.h"

class CustomerLogin {
 protected:
  int state_customer_login = 0;  // 0 mean no need to run customer login again,
                                 // 1 means need to run again.
 public:
  // runs the portal
  void run(int& state_portal);

  // gets the value of state_customer_login (0 or 1)
  int get_state_customer_login();

  // default constructor and destructor
  CustomerLogin();
  ~CustomerLogin();
};

#endif