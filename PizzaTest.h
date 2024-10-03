#include "Pizza.h"

class PizzaTest {
private:
    // default test with default constructor
    void test_pizza_default() {
        Pizza p;
        if (p.get_pizzaBase() != "N/A") {
            cout << "default test for pizza base failed, result unexpected" << endl;
        }
        if (p.get_pizzaSauce() != "N/A") {
            cout << "default test for pizza sauce failed, result unexpected" << endl;
        }
        if (p.get_item_name() != "N/A") {
            cout << "default test for pizza name failed, result unexpected" << endl;
        }
        if (p.get_item_price() != 0.0) {
            cout << "default test for pizza price failed, result unexpected" << endl;
        }
        if (p.get_item_size() != 1) {
            cout << "default test for pizza size failed, result unexpected" << endl;
        }
    }

    // default test with no ingredient
    void test_pizza_case1() {
        Pizza p1;
        p1 = Pizza("P", 1.2, 1, "Base1", "Sauce1");
        if (p1.get_pizzaBase() != "Base1") {
            cout << "default test for pizza base failed, result unexpected" << endl;
        }
        if (p1.get_pizzaSauce() != "Sauce1") {
            cout << "default test for pizza sauce failed, result unexpected" << endl;
        }
        if(p1.get_item_size() != 2) {
            cout << "test 1 size failed, result unexpected" << endl;
        }
        if(p1.get_item_name() != "Coke") {
            cout << "test 1 name failed, result unexpected" << endl;
        }
        if(p1.get_item_price() != 2.2) {
            cout << "test 1 price failed, result unexpected" << endl;
        }
        if(p1.calculate_item_price() != 2.75) {
            cout << "test 1 price calculation failed, result unexpected" << endl;
        }
    }
public:
    void run_tests() {
        test_pizza_default();
        test_pizza_case1();
    }
};

