#ifndef CUSTOMER_LOGIN_H
#define CUSTOMER_LOGIN_H

#include "portal.h"

class customer_login : public portal{
 private:
  int state_customer_login =
      0;  // 0 mean no need to run customer login again, 1 means need to run again.
 public:
  void run();
  int get_state_customer_login();
  customer_login();
  ~customer_login();
};

#endif