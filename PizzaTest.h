#include "Pizza.h"

class PizzaTest {
private:
    // default test with default constructor
    void test_pizza_default() {
        // Create a pizza via the default constructor
        Pizza p;

         // compare the values against the expected sauce/base/name/price/size
        if (p.get_pizza_sauce() != "N/A") {
            cout << "default test for pizza sauce failed, result unexpected" << endl;
        }
        if (p.get_pizza_cheese() != "N/A") {
            cout << "default test for pizza base failed, result unexpected" << endl;
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

    // test 1 with no ingredient
    void test_pizza_case1() {
        // Create a pizza with parameters (excluding ingredient)
        Pizza p1 = Pizza("P1", 1.2, 1, "Sauce1", "Cheese1");

        // compare the values against the expected sauce/base/name/price/size
        if (p1.get_pizza_sauce() != "Sauce1") {
            cout << "test 1 for pizza sauce failed, result unexpected" << endl;
        }
        if (p1.get_pizza_cheese() != "Cheese1") {
            cout << "test 1 for pizza cheese failed, result unexpected" << endl;
        }
        if (p1.get_item_size() != 1) {
            cout << "test 1 for pizza size failed, result unexpected" << endl;
        }
        if (p1.get_item_name() != "P1") {
            cout << "test 1 for pizza name failed, result unexpected" << endl;
        }
        if (p1.get_item_price() != 1.2) {
            cout << "test 1 for pizza price failed, result unexpected" << endl;
        }
        if (p1.calculate_item_price() != 1.2) {
            cout << "test 1 for pizza price calculation failed, result unexpected" << endl;
        }
    }

    // test 2 with 1 ingredient
    void test_pizza_case2() {
        // Create a pizza with parameters (including 1 ingredient) 
        Pizza p2; 
        Ingredient I1;
        I1 = Ingredient("Ingredient1", 0.5);
        p2 = Pizza("P2", 3.5, 2, "Sauce2", "Cheese2", {I1});

        // compare the ingredient and final price against the expected ingredient/price    
        if (p2.get_ingredient(0).get_name() != "Ingredient1") {
            cout << "test 2 for pizza ingredient 1 name failed, result unexpected" << endl;
        }
        if (p2.get_ingredient(0).get_price() != 0.5) {
            cout << "test 2 for pizza ingredient 1 price failed, result unexpected" << endl;
        }
        if (p2.calculate_item_price() != (3.5*1.25+0.5)) {
            cout << "test 2 for pizza price calculation failed, result unexpected" << endl;
        }
    }

    // Test 3 with multiple ingredients + changing values
    void test_pizza_case3() {
        // Create a pizza with parameters (including multiple ingredients) 
        Ingredient I1 = Ingredient("Ingredient1", 0.5);
        Ingredient I2 = Ingredient();
        Ingredient I3 = Ingredient("I3", 1.5);
        Pizza p3 = Pizza("P2", 3.5, 2, "Sauce2", "Cheese2", {I1});

        // change the parameters with set functions 
        p3.set_item_name("P3");
        p3.set_item_price(6);
        p3.set_item_size("large");
        p3.set_pizza_cheese("Cheese3");
        p3.set_pizza_sauce("Sauce3");
        p3.add_ingredient(I2);
        p3.add_ingredient(I3);

        // compare the parameters, ingredients, and final price against the expected ingredient/price
        if (p3.get_pizza_sauce() != "Sauce3") {
            cout << "test 3 for pizza sauce failed, result unexpected" << endl;
        }
        if (p3.get_pizza_cheese() != "Cheese3") {
            cout << "test 3 for pizza cheese failed, result unexpected" << endl;
        }
        if (p3.get_item_size() != 3) {
            cout << "test 3 for pizza size failed, result unexpected" << endl;
        }
        if (p3.get_item_name() != "P3") {
            cout << "test 3 for pizza name failed, result unexpected" << endl;
        }
        if (p3.get_item_price() != 6) {
            cout << "test 3 for pizza price failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(0).get_name() != "Ingredient1") {
            cout << "test 3 for pizza ingredient 1 name failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(0).get_price() != 0.5) {
            cout << "test 3 for pizza ingredient 1 price failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(1).get_name() != "N/A") {
            cout << "test 3 for pizza ingredient 2 name failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(1).get_price() != 0) {
            cout << "test 3 for pizza ingredient 2 price failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(2).get_name() != "I3") {
            cout << "test 3 for pizza ingredient 3 name failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(2).get_price() != 1.5) {
            cout << "test 3 for pizza ingredient 3 price failed, result unexpected" << endl;
        }
        if (p3.calculate_item_price() != (6*1.5+0.5+1.5)) {
            cout << "test 3 for pizza price calculation failed, result unexpected" << endl;
        }
    }
public:
    // runs the test cases above
    void run_tests() {
        test_pizza_default();
        test_pizza_case1();
        test_pizza_case2();
        test_pizza_case3();
    }
};

