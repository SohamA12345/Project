#include "Portal.h"

class PortalTest {
private:
    void base_test() {
        int t = 1;
        Portal P;
        P.run();
        // P.get_state_customer_login();
        // if (C.get_state_customer_login() != 1) {
        //     cout << "The customer login isn't correct" << endl;
        // }
        
    }
public:
    void run_tests() {
        base_test();
    }
};

