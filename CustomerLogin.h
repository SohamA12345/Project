#ifndef CUSTOMER_LOGIN_H
#define CUSTOMER_LOGIN_H

#include "FoodItem.h"

class CustomerLogin {
 protected:
<<<<<<< HEAD
  int state_customer_login = 0;  // 0 mean no need to run customer login again,
                                 // 1 means need to run again.
=======
  // 0 mean no need to run customer login again, 1 means need to rerun.
  int state_customer_login = 0;  
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46
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