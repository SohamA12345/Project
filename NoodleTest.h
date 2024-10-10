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

    // test case 1 for noodles, no ingredient
    void test_noodle_case1() {
        Noodle n1 = Noodle("noodle1", 1.1, 1, "type1", "soup1");
        if (n1.get_noodle_soup() != "soup1") {
            cout << "test 1 for pasta sauce failed, result unexpected" << endl;
        }
        if (n1.get_noodle_type() != "type1") {
            cout << "test 1 for pasta type failed, result unexpected" << endl;
        }
        if (n1.get_item_name() != "noodle1") {
            cout << "test 1 for pasta name failed, result unexpected" << endl;
        }
        if (n1.get_item_price() != 1.1) {
            cout << "test 1 for pasta price failed, result unexpected" << endl;
        }
        if (n1.get_item_size() != 1) {
            cout << "test 1 for pasta size failed, result unexpected" << endl;
        }
    }

    // test case 2 with 1 ingredient
    void test_noodle_case2() {
        Ingredient I1 = Ingredient("i1", 0.1);
        Noodle n2 = Noodle("noodle2", 2.2, 2, "type2", "soup2", {I1});
        if (n2.get_noodle_soup() != "soup2") {
            cout << "test 2 for noodle soup failed, result unexpected" << endl;
        }
        if (n2.get_noodle_type() != "type2") {
            cout << "test 2 for noodle type failed, result unexpected" << endl;
        }
        if (n2.get_item_name() != "noodle2") {
            cout << "test 2 for noodle name failed, result unexpected" << endl;
        }
        if (n2.get_item_price() != 2.2) {
            cout << "test 2 for noodle price failed, result unexpected" << endl;
        }
        if (n2.get_item_size() != 2) {
            cout << "test 2 for noodle size failed, result unexpected" << endl;
        }
        if (n2.get_ingredient(0).get_name() != "i1") {
            cout << "test 2 for noodle ingredient name failed, result unexpected" << endl;
        }
        if (n2.get_ingredient(0).get_price() != 0.1) {
            cout << "test 2 for noodle ingredient price failed, result unexpected" << endl;
        }
        if (n2.calculate_item_price() != (2.2*1.25+0.1)) {
            cout << "test 2 for noodle price calculation failed, result unexpected " << endl;
        }
    }

    // test case 3 with multiple ingredients and changing the values of variables
    void test_noodle_case3() {
        Ingredient I1 = Ingredient("I1", 0.3);
        Ingredient I2 = Ingredient();
        Ingredient I3 = Ingredient("Ingredient3", 0.7);
        Noodle n3 = Noodle("noodle2", 2.2, 2, "type2", "soup2", {I1});
        n3.set_item_name("noodle3");
        n3.set_item_price(10);
        n3.set_item_size("large");
        n3.set_noodle_soup("soup3");
        n3.set_noodle_type("type3");
        n3.set_ingredient_list({I1, I2});
        n3.add_ingredient(I3);
        if (n3.get_noodle_soup() != "soup3") {
            cout << "test 3 for noodle soup failed, result unexpected" << endl;
        }
        if (n3.get_noodle_type() != "type3") {
            cout << "test 3 for noodle type failed, result unexpected" << endl;
        }
        if (n3.get_item_name() != "noodle3") {
            cout << "test 3 for noodle name failed, result unexpected" << endl;
        }
        if (n3.get_item_price() != 10) {
            cout << "test 3 for noodle price failed, result unexpected" << endl;
        }
        if (n3.get_item_size() != 3) {
            cout << "test 3 for noodle size failed, result unexpected" << endl;
        }
        if (n3.get_ingredient(0).get_name() != "I1") {
            cout << "test 3 for noodle ingredient 1 name failed, result unexpected" << endl;
        }
        if (n3.get_ingredient(0).get_price() != 0.3) {
            cout << "test 3 for noodle ingredient 1 price failed, result unexpected" << endl;
        }
        if (n3.get_ingredient(1).get_name() != "N/A") {
            cout << "test 3 for noodle ingredient 2 name failed, result unexpected" << endl;
        }
        if (n3.get_ingredient(1).get_price() != 0) {
            cout << "test 3 for noodle ingredient 2 price failed, result unexpected" << endl;
        }
        if (n3.get_ingredient(2).get_name() != "Ingredient3") {
            cout << "test 3 for noodle ingredient 3 name failed, result unexpected" << endl;
        }
        if (n3.get_ingredient(2).get_price() != 0.7) {
            cout << "test 3 for noodle ingredient 3 price failed, result unexpected" << endl;
        }
        if (n3.calculate_item_price() != (10*1.5+0.3+0.7)) {
            cout << "test 3 for noodle price calculation failed, result unexpected " << endl;
        }
    }
public:
    void run_tests() {
        test_noodle_default();
        test_noodle_case1();
        test_noodle_case2();
        test_noodle_case3();
    }
};

