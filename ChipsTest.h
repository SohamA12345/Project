#include "Chips.h"

class ChipsTest {
private:
    // default test case for chips
    void test_chips_default() {
        // Create a chips via the default constructor
        Chips c;

        // compare the values against the expected cut/seasoning/name/price/size
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
        // Create a chips with parameters (excluding ingredient) 
        Chips c1 = Chips("chips1", 3.5, 1, "cut1", "seasoning1");

        // then compare the values against the expected cut/seasoning/name/price/size
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

    // test case 2 for chips, with 1 ingredient
    void test_chips_case2() {
        // Create a chips with parameters (including 1 ingredient)
        Ingredient i1 = Ingredient("i1", 0.2);
        Chips c2 = Chips("chips2", 5, 2, "cut2", "seasoning2", {i1});

        // then compare the ingredient and final price against the expected ingredient/price
        if (c2.get_ingredient(0).get_name() != "i1") {
            cout << "test 2 for rice ingredient 1 name failed, result unexpected" << endl;
        }
        if (c2.get_ingredient(0).get_price() != 0.2) {
            cout << "test 2 for rice ingredient 1 price failed, result unexpected" << endl;
        }
        if (c2.calculate_item_price() != (5*1.25+0.2)) {
            cout << "test 2 for chips price calculation failed, result unexpected" << endl;
        }
    }

    // Test case 3 for chips, with multiple ingredients, and setting values for variables
    void test_chips_case3() {
        // Create a chips with parameters (including multiple ingredients)
        Ingredient i1 = Ingredient("i1", 0.2);
        Ingredient i2;
        Ingredient i3 = Ingredient("ingredient3", 0.8);
        Chips c3 = Chips("chips2", 5, 2, "cut2", "seasoning2", {i1, i2});

        // change the parameters with set functions, 
        c3.set_item_name("chips3");
        c3.set_item_price(6.5);
        c3.set_item_size("large");
        c3.set_chips_cut("cut3");
        c3.set_chips_seasoning("seasoning3");
        c3.set_ingredient_list({i1});  
        c3.add_ingredient(i3);

        // compare the parameters, ingredients, and final price against the expected ingredient/price
        if (c3.get_chips_cut() != "cut3") {
            cout << "test 3 for chips cut failed, result unexpected" << endl;
        }
        if (c3.get_chips_seasoning() != "seasoning3") {
            cout << "test 3 for chips seasoning failed, result unexpected " << endl;
        }
        if (c3.get_item_name() != "chips3") {
            cout << "test 3 for chips name failed, result unexpected" << endl;
        }
        if (c3.get_item_price() != 6.5) {
            cout << "test 3 for chips price failed, result unexpected" << endl;
        }
        if (c3.get_item_size() != 3) {
            cout << "test 3 for chips size failed, result unexpected" << endl;
        }
        if (c3.get_ingredient(0).get_name() != "i1") {
            cout << "test 3 for rice ingredient 1 name failed, result unexpected" << endl;
        }
        if (c3.get_ingredient(0).get_price() != 0.2) {
            cout << "test 3 for rice ingredient 1 price failed, result unexpected" << endl;
        }
        if (c3.get_ingredient(1).get_name() != "ingredient3") {
            cout << "test 3 for rice ingredient 2 name failed, result unexpected" << endl;
        }
        if (c3.get_ingredient(1).get_price() != 0.8) {
            cout << "test 3 for rice ingredient 2 price failed, result unexpected" << endl;
        }
        if (c3.calculate_item_price() != (6.5*1.5+0.8+0.2)) {
            cout << "test 3 for chips price calculation failed, result unexpected" << endl;
        }
    }
public:
    // run_tests runs the test cases created above 
    void run_tests() {
        test_chips_default();
        test_chips_case1();
        test_chips_case2();
        test_chips_case3();
    }
};

