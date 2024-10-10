#include "Pasta.h"

class PastaTest {
private:
    // default test case for pasta 
    void test_pasta_default() {
        Pasta p;
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
        Pasta p1 = Pasta("Pasta1", 1.2, 1, "Type1", "Sauce1");        
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
public:
    void run_tests() {
        test_pasta_default();
        test_pasta_case1();
    }
};

