#include "Rice.h" 

class RiceTest {
private:
    // default test case for rice
    void test_rice_default() {
        // Create a rice via the default constructor
        Rice r;

        // compare the values against the expected type/name/price/size
        if (r.get_rice_type() != "N/A") {
            cout << "default test for rice type failed, result unexpected" << endl;
        }
        if (r.get_item_name() != "N/A") {
            cout << "default test for rice name failed, result unexpected" << endl;
        }
        if (r.get_item_price() != 0.0) {
            cout << "default test for rice price failed, result unexpected" << endl;
        }
        if (r.get_item_size() != 1) {
            cout << "default test for rice size failed, result unexpected" << endl;
        }
    }

    // test case 1 for rice, no ingredient
    void test_rice_case1() {
        // Create a rice with parameters (excluding ingredient)
        Rice r1 = Rice("rice1", 3.1, 1, "type1");        

        // compare the values against the expected type/name/price/size
        if (r1.get_rice_type() != "type1") {
            cout << "test 1 for rice sauce failed, result unexpected" << endl;
        }
        if (r1.get_item_name() != "rice1") {
            cout << "test 1 for rice name failed, result unexpected" << endl;
        }
        if (r1.get_item_price() != 3.1) {
            cout << "test 1 for rice price failed, result unexpected" << endl;
        }
        if (r1.get_item_size() != 1) {
            cout << "test 1 for rice size failed, result unexpected" << endl;
        }
        if (r1.calculate_item_price() != 3.1) {
            cout << "test 1 for rice price calculation failed, result unexpected" << endl;
        }
        
    }
    

    // test case 2 for rice, with 1 ingredient
    void test_rice_case2() {
        // Create a rice with parameters (including 1 ingredient) 
        Ingredient i1 = Ingredient("i1", 0.1);
        Rice r2 = Rice("rice2", 4.4, 2, "type2", {i1});    

        // compare the ingredient and final price against the expected ingredient/price    
        if (r2.get_ingredient(0).get_name() != "i1") {
            cout << "test 2 for rice ingredient 1 name failed, result unexpected" << endl;
        }
        if (r2.get_ingredient(0).get_price() != 0.1) {
            cout << "test 2 for rice ingredient 1 price failed, result unexpected" << endl;
        }
        if (r2.calculate_item_price() != (4.4*1.25+0.1)) {
            cout << "test 2 for rice price calculation failed, result unexpected" << endl;
        }
    }

    // test case 3 for rice, with multiple ingredients and setting the values for variables
    void test_rice_case3() {
        // Create a rice with parameters (including multiple ingredients) 
        Ingredient i1 = Ingredient("i1", 0.1);
        Ingredient i2 = Ingredient();
        Ingredient i3 = Ingredient("Ingredient3", 0.9);
        Rice r3 = Rice("rice2", 4.4, 2, "type2", {i1});  

        // change the parameters with set functions 
        r3.set_item_name("rice3");
        r3.set_item_price(10);
        r3.set_item_size("large");
        r3.set_rice_type("type3");
        r3.set_ingredient_list({i1, i2});  
        r3.add_ingredient(i3);

        // compare the parameters, ingredients, and final price against the expected ingredient/price
        if (r3.get_rice_type() != "type3") {
            cout << "test 3 for rice type failed, result unexpected" << endl;
        }
        if (r3.get_item_name() != "rice3") {
            cout << "test 3 for rice name failed, result unexpected" << endl;
        }
        if (r3.get_item_price() != 10) {
            cout << "test 3 for rice price failed, result unexpected" << endl;
        }
        if (r3.get_item_size() != 3) {
            cout << "test 3 for rice size failed, result unexpected" << endl;
        }     
        if (r3.get_ingredient(0).get_name() != "i1") {
            cout << "test 3 for rice ingredient 1 name failed, result unexpected" << endl;
        }
        if (r3.get_ingredient(0).get_price() != 0.1) {
            cout << "test 3 for rice ingredient 1 price failed, result unexpected" << endl;
        }
        if (r3.get_ingredient(1).get_name() != "N/A") {
            cout << "test 3 for rice ingredient 2 name failed, result unexpected" << endl;
        }
        if (r3.get_ingredient(1).get_price() != 0) {
            cout << "test 3 for rice ingredient 2 price failed, result unexpected" << endl;
        }
        if (r3.get_ingredient(2).get_name() != "Ingredient3") {
            cout << "test 3 for rice ingredient 3 name failed, result unexpected" << endl;
        }
        if (r3.get_ingredient(2).get_price() != 0.9) {
            cout << "test 3 for rice ingredient 3 price failed, result unexpected" << endl;
        }
        if (r3.calculate_item_price() != (10*1.5+0.1+0.9)) {
            cout << "test 3 for rice price calculation failed, result unexpected" << endl;
        }
    }
public:
    // runs the test cases above
    void run_tests() {
        test_rice_default();
        test_rice_case1();
        test_rice_case2();
        test_rice_case3();
    }
};

