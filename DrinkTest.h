// this is the unit test file for Drink.h
#include "MenuItem.h"
#include "Drink.h"

class DrinkTest {
private:
    // default case with no input
    void test_drink_default() {
        Drink d1;
        if(d1.get_sugar() != 0) {
            cout << "default test sugar failed, result unexpected" << endl;
        }
        if(d1.show_ice() != 0) {
            cout << "default test ice failed, result unexpected" << endl;
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

    // 2nd case with input
    void test_drink_case1() {
        Drink d1;
        d1 = Drink(2, "Coke", 2.2);
        if(d1.get_sugar() != 0) {
            cout << "test 1 sugar failed, result unexpected" << endl;
        }
        if(d1.show_ice() != 0) {
            cout << "test 1 ice failed, result unexpected" << endl;
        }
        if(d1.get_item_size() != 2) {
            cout << "test 1 size failed, result unexpected" << endl;
        }
        if(d1.get_item_name() != "Coke") {
            cout << "test 1 name failed, result unexpected" << endl;
        }
        if(d1.get_item_price() != 2.2) {
            cout << "test 1 price failed, result unexpected" << endl;
        }
        if(d1.calculate_item_price() != 2.75) {
            cout << "test 1 price calculation failed, result unexpected" << endl;
        }
    }

    // 3rd case that alters the inputs
    void test_drink_case2() {
        Drink d2;
        d2.set_item_size("medium");
        d2.set_item_name("Sprite");
        d2.set_item_price(5.0);
        d2.add_sugar(2);
        d2.change_ice();
        if(d2.get_sugar() != 2) {
            cout << "test 2 sugar failed, result unexpected" << endl;
        }
        if(d2.show_ice() != 1) {
            cout << "test 2 ice failed, result unexpected" << endl;
        }
        if(d2.get_item_size() != 2) {
            cout << "test 2 size failed, result unexpected" << endl;
        }
        if(d2.get_item_name() != "Sprite") {
            cout << "test 2 name failed, result unexpected" << endl;
        }
        if(d2.get_item_price() != 5.0) {
            cout << "test 2 price failed, result unexpected" << endl;
        }
        if(d2.calculate_item_price() != 6.25) {
            cout << "test 2 price calculation failed, result unexpected" << endl;
        }
    }
public:
    void run_tests() {
        test_drink_default();
        test_drink_case1();
        test_drink_case2();
    };
};