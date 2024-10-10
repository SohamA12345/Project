#include "Noodle.h"

class NoodleTest {
private:
    // default test case for noodles
    void test_noodle_default() {
        Noodle n;
        if (n.get_noodle_soup() != "N/A") {
            cout << "default test for pasta sauce failed, result unexpected" << endl;
        }
        if (n.get_noodle_type() != "N/A") {
            cout << "default test for pasta type failed, result unexpected" << endl;
        }
        if (n.get_item_name() != "N/A") {
            cout << "default test for pasta name failed, result unexpected" << endl;
        }
        if (n.get_item_price() != 0.0) {
            cout << "default test for pasta price failed, result unexpected" << endl;
        }
        if (n.get_item_size() != 1) {
            cout << "default test for pasta size failed, result unexpected" << endl;
        }
    }

    
public:
    void run_tests() {
        test_noodle_default();
    }
};

