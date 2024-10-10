#include "Pizza.h"

class PizzaTest {
private:
    // default test with default constructor
    void test_pizza_default() {
        Pizza p;
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
        Pizza p1;
        p1 = Pizza("P1", 1.2, 1, "Sauce1", "Cheese1");
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
        Pizza p2; 
        Ingredient I1;
        I1 = Ingredient("Ingredient1", 0.5);
        p2 = Pizza("P2", 3.5, 2, "Sauce2", "Cheese2", {I1});
        if (p2.get_pizza_sauce() != "Sauce2") {
            cout << "test 2 for pizza sauce failed, result unexpected" << endl;
        }
        if (p2.get_pizza_cheese() != "Cheese2") {
            cout << "test 2 for pizza cheese failed, result unexpected" << endl;
        }
        if (p2.get_item_size() != 2) {
            cout << "test 2 for pizza size failed, result unexpected" << endl;
        }
        if (p2.get_item_name() != "P2") {
            cout << "test 2 for pizza name failed, result unexpected" << endl;
        }
        if (p2.get_item_price() != 3.5) {
            cout << "test 2 for pizza price failed, result unexpected" << endl;
        }
        if (p2.calculate_item_price() != 4) {
            cout << "test 2 for pizza price calculation failed, result unexpected" << endl;
        }
        cout << "expected outcome: Ingredient1 | $0.5" << endl;
        cout << "actual outcome: ";
        p2.print_ingredients_and_price();
    }

    // Test 3 with multiple ingredients + changing values
    void test_pizza_case3() {
        Ingredient I1 = Ingredient("Ingredient1", 0.5);
        Ingredient I2 = Ingredient();
        Ingredient I3 = Ingredient("I3", 1.5);
        Pizza p3 = Pizza("P2", 3.5, 2, "Sauce2", "Cheese2", {I1});
        p3.set_item_name("P3");
        p3.set_item_price(6);
        p3.set_item_size("large");
        p3.set_pizza_cheese("Cheese3");
        p3.set_pizza_sauce("Sauce3");
        p3.add_ingredient(I2);
        p3.add_ingredient(I3);
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
        if (p3.calculate_item_price() != (6+0.5+1.5)) {
            cout << "test 3 for pizza price calculation failed, result unexpected" << endl;
        }
        cout << "expected outcome: Ingredient1 | $0.5 \nNoName | $0 \nI3 | $1.5 " << endl;
        cout << "actual outcome: ";
        p3.print_ingredients_and_price();
    }
public:
    void run_tests() {
        test_pizza_default();
        test_pizza_case1();
        test_pizza_case2();
        test_pizza_case3();
    }
};

