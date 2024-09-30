// this is the unit test file for menu_item.h
#include "menu_item.h"
#include "drink.h"

class drink_test {
public:
    void run_tests() {
        test_drink_default();
        test_drink_case1();
    };
private:
    void test_drink_default() {
        drink d1;
        if(d1.get_sugar() != 0) {
            cout << "test 1 sugar failed, result unexpected" << endl;
        }
        if(d1.show_ice() != 0) {
            cout << "test 1 ice failed, result unexpected" << endl;
        }
        if(d1.get_item_size() != 1) {
            cout << "test 1 size failed, result unexpected" << endl;
        }
        if(d1.get_item_name() != "N/A") {
            cout << "test 1 name failed, result unexpected" << endl;
        }
        if(d1.get_item_price() != 0) {
            cout << "test 1 price failed, result unexpected" << endl;
        }
    }

    void test_drink_case1() {
        drink d1;
        d1 = drink(2, "Coke", 2.2);
        if(d1.get_sugar() != 0) {
            cout << "test 2 sugar failed, result unexpected" << endl;
        }
        if(d1.show_ice() != 0) {
            cout << "test 2 ice failed, result unexpected" << endl;
        }
        if(d1.get_item_size() != 2) {
            cout << "test 2 size failed, result unexpected" << endl;
        }
        if(d1.get_item_name() != "Coke") {
            cout << "test 2 name failed, result unexpected" << endl;
        }
        if(d1.get_item_price() != 2.2) {
            cout << "test 2 price failed, result unexpected" << endl;
        }
        if(d1.calculate_item_price() != 2.75) {
            cout << "test 2 price calculation failed, result unexpected" << endl;
        }
    }

    
};