#include "ManagerLogin.h"
using namespace std;
#include <iostream>

class ManagerLoginTest {
 private:
  void base_test() {
    int t = 1;
    ManagerLogin M;
    M.run(t);
    // M.get_state_customer_login();
    //  if (C.get_state_customer_login() != 1) {
    //      cout << "The customer login isn't correct" << endl;
    //  }
  }

 public:
  void run_tests() { base_test(); }
};
