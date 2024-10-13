#include "Pasta.h"

class PastaTest {
private:
    // default test case for pasta 
    void test_pasta_default() {
        // Create a pasta via the default constructor 
        Pasta p;

        // compare the values against the expected sauce/type/name/price/size
        if (p.get_pasta_sauce() != "N/A") {
            cout << "default test for pasta sauce failed, result unexpected" << endl;
        }
        if (p.get_pasta_type() != "N/A") {
            cout << "default test for pasta type failed, result unexpected" << endl;
        }
        if (p.get_item_name() != "N/A") {
            cout << "default test for pasta name failed, result unexpected" << endl;
        }
        if (p.get_item_price() != 0.0) {
            cout << "default test for pasta price failed, result unexpected" << endl;
        }
        if (p.get_item_size() != 1) {
            cout << "default test for pasta size failed, result unexpected" << endl;
        }
    }

    // test 1 with no ingredients
    void test_pasta_case1() {
        // Create a pasta with parameters (excluding ingredient)
        Pasta p1 = Pasta("Pasta1", 1.2, 1, "Type1", "Sauce1");    

        // compare the values against the expected sauce/type/name/price/size
        if (p1.get_pasta_sauce() != "Sauce1") {
            cout << "test 1 for pasta sauce failed, result unexpected" << endl;
        }
        if (p1.get_pasta_type() != "Type1") {
            cout << "test 1 for pasta type failed, result unexpected" << endl;
        }
        if (p1.get_item_name() != "Pasta1") {
            cout << "test 1 for pasta name failed, result unexpected" << endl;
        }
        if (p1.get_item_price() != 1.2) {
            cout << "test 1 for pasta price failed, result unexpected" << endl;
        }
        if (p1.get_item_size() != 1) {
            cout << "test 1 for pasta size failed, result unexpected" << endl;
        }
        if (p1.calculate_item_price() != 1.2) {
            cout << "test 1 for pasta price calculation failed, result unexpected" << endl;
        }
    }

    // test 2 with 1 ingredient
    void test_pasta_case2() {
        // Create a pasta with parameters (including 1 ingredient) 
        Ingredient I1 = Ingredient("I1", 0.4);
        Pasta p2 = Pasta("Pasta2", 4.4, 2, "Type2", "Sauce2", {I1});    

        // compare the ingredient and final price against the expected ingredient/price    
        if (p2.get_ingredient(0).get_name() != "I1") {
            cout << "test 2 for pasta ingredient 1 name failed, result unexpected" << endl;
        }
        if (p2.get_ingredient(0).get_price() != 0.4) {
            cout << "test 2 for pasta ingredient 1 price failed, result unexpected" << endl;
        }
        if (p2.calculate_item_price() != (4.4*1.25+0.4)) {
            cout << "test 2 for pasta price calculation failed, result unexpected" << endl;
        }
    }

    // test 3 with changing (setting variables) + multiple ingredients
    void test_pasta_case3() {
        // Create a pasta with parameters (including multiple ingredients) 
        Ingredient I1 = Ingredient("I1", 0.4);
        Ingredient I2 = Ingredient();
        Ingredient I3 = Ingredient("Ingredient3", 0.6);
        Pasta p3 = Pasta("Pasta2", 4.4, 2, "Type2", "Sauce2", {I1}); 

        // change the parameters with set functions 
        p3.set_item_name("Pasta3");
        p3.set_item_price(3.3);
        p3.set_item_size("large");
        p3.set_pasta_sauce("Sauce3");
        p3.set_pasta_type("Type3");
        p3.set_ingredient_list({I1, I2, I3});

        // compare the parameters, ingredients, and final price against the expected ingredient/price
        if (p3.get_pasta_sauce() != "Sauce3") {
            cout << "test 3 for pasta sauce failed, result unexpected" << endl;
        }
        if (p3.get_pasta_type() != "Type3") {
            cout << "test 3 for pasta type failed, result unexpected" << endl;
        }
        if (p3.get_item_name() != "Pasta3") {
            cout << "test 3 for pasta name failed, result unexpected" << endl;
        }
        if (p3.get_item_price() != 3.3) {
            cout << "test 3 for pasta price failed, result unexpected" << endl;
        }
        if (p3.get_item_size() != 3) {
            cout << "test 3 for pasta size failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(0).get_name() != "I1") {
            cout << "test 3 for pasta ingredient 1 name failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(0).get_price() != 0.4) {
            cout << "test 3 for pasta ingredient 1 price failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(1).get_name() != "N/A") {
            cout << "test 3 for pasta ingredient 2 name failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(1).get_price() != 0) {
            cout << "test 3 for pasta ingredient 2 price failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(2).get_name() != "Ingredient3") {
            cout << "test 3 for pasta ingredient 1 name failed, result unexpected" << endl;
        }
        if (p3.get_ingredient(2).get_price() != 0.6) {
            cout << "test 3 for pasta ingredient 1 price failed, result unexpected" << endl;
        }
        if (p3.calculate_item_price() != (3.3*1.5+0.4+0.6)) {
            cout << "test 3 for pasta price calculation failed, result unexpected" << endl;
        }
    }
public:
    // run_tests runs the test cases above
    void run_tests() {
        test_pasta_default();
        test_pasta_case1();
        test_pasta_case2();
        test_pasta_case3();
    }
};

