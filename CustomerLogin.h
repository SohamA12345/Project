#ifndef CUSTOMER_LOGIN_H
#define CUSTOMER_LOGIN_H

#include "FoodItem.h"

class CustomerLogin{
 private:
  int state_customer_login =
      0;  // 0 mean no need to run customer login again, 1 means need to run again.
 public:
  void run(int& state_portal);
  int get_state_customer_login();
  CustomerLogin();
  ~CustomerLogin();
};

#endif