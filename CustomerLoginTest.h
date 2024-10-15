#include "CustomerLogin.h"
using namespace std;
#include <iostream>

class CustomerLoginTest {
 private:
  void base_test() {
    int t = 1;
    CustomerLogin C;
    C.run(t);
    C.get_state_customer_login();
    if (C.get_state_customer_login() != 1) {
      cout << "The customer login isn't correct" << endl;
    }
  }

 public:
  void run_tests() { base_test(); }
};
