#include "Chips.h"

class ChipsTest {
private:
    // default test case for chips
    void test_chips_default() {
        Chips c;
        if (c.get_chips_cut() != "N/A") {
            cout << "default test for chips cut failed, result unexpected" << endl;
        }
        if (c.get_chips_seasoning() != "N/A") {
            cout << "default test for chips seasoning failed, result unexpected " << endl;
        }
        if (c.get_item_name() != "N/A") {
            cout << "default test for chips name failed, result unexpected" << endl;
        }
        if (c.get_item_price() != 0.0) {
            cout << "default test for chips price failed, result unexpected" << endl;
        }
        if (c.get_item_size() != 1) {
            cout << "default test for chips size failed, result unexpected" << endl;
        }
    }

    // test case 1 for chips, no seasoning
    void test_chips_case1() {
        Chips c1 = Chips("chips1", 3.5, 1, "cut1", "seasoning1");
        if (c1.get_chips_cut() != "cut1") {
            cout << "test 1 for chips cut failed, result unexpected" << endl;
        }
        if (c1.get_chips_seasoning() != "seasoning1") {
            cout << "test 1 for chips seasoning failed, result unexpected " << endl;
        }
        if (c1.get_item_name() != "chips1") {
            cout << "test 1 for chips name failed, result unexpected" << endl;
        }
        if (c1.get_item_price() != 3.5) {
            cout << "test 1 for chips price failed, result unexpected" << endl;
        }
        if (c1.get_item_size() != 1) {
            cout << "test 1 for chips size failed, result unexpected" << endl;
        }
    }

    // 
    void test_chips_case2() {

    }

    // 
    void test_chips_case3() {

    }
public:
    void run_tests() {
        test_chips_default();
        test_chips_case1();
        test_chips_case2();
        test_chips_case3();
    }
};

