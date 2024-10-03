#include "Portal.h"

class PortalTest {
private:
    void base_portal_test() {
        Portal p;
        p.get_state_portal();
    }
    
public:
    void run_tests() {
        base_portal_test();
    }
};

