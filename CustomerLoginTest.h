#include "CustomerLogin.h"

class CustomerLoginTest {
private:
    void base_test() {
        int t = 1;
        CustomerLogin C;
        C.run(t);
        C.get_state_customer_login();
    }
public:
    void run_tests() {
        base_test();
    }
};
