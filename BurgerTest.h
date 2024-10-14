#include "Burger.h"

class BurgerTest {
 private:
  // this is the default test case for burger
  void test_Burger_default() {
    // Create a burger via the default constructor,
    Burger b;

    // compare the values against the expected bun/meat/name/price/size
    if (b.get_burger_bun() != "N/A") {
      cout << "default test for burger bun failed, result unexpected" << endl;
    }
    if (b.get_burger_meat() != "N/A") {
      cout << "default test for burger meat failed, result unexpected " << endl;
    }
    if (b.get_item_name() != "N/A") {
      cout << "default test for burger name failed, result unexpected" << endl;
    }
    if (b.get_item_price() != 0.0) {
      cout << "default test for burger price failed, result unexpected" << endl;
    }
    if (b.get_item_size() != 1) {
      cout << "default test for burger size failed, result unexpected" << endl;
    }
  }

  // this is test case 1 for burger, no ingredient
  void test_Burger_case1() {
    // Create a burger with parameters (excluding ingredient)
    Burger b1 = Burger("burger1", 3.1, 1, "bun1", "meat1");

    // compare the values against the expected bun/meat/name/price/size
    if (b1.get_burger_bun() != "bun1") {
      cout << "test 1 for burger bun failed, result unexpected" << endl;
    }
    if (b1.get_burger_meat() != "meat1") {
      cout << "test 1 for burger meat failed, result unexpected " << endl;
    }
    if (b1.get_item_name() != "burger1") {
      cout << "test 1 for burger name failed, result unexpected" << endl;
    }
    if (b1.get_item_price() != 3.1) {
      cout << "test 1 for burger price failed, result unexpected" << endl;
    }
    if (b1.get_item_size() != 1) {
      cout << "test 1 for burger size failed, result unexpected" << endl;
    }
  }

  // test case 2 for burger, with ingredient
  void test_Burger_case2() {
    // Create a burger with parameters (including 1 ingredient)
    Ingredient i1 = Ingredient("i1", 1);

    // compare the ingredient and final price against the expected
    // ingredient/price
    Burger b2 = Burger("burger2", 3.3, 2, "bun1", "meat1", {i1});
    if (b2.get_ingredient(0).get_name() != "i1") {
      cout << "test 2 for burger ingredient 1 name failed, result unexpected"
           << endl;
    }
    if (b2.get_ingredient(0).get_price() != 1) {
      cout << "test 2 for burger ingredient 1 price failed, result unexpected"
           << endl;
    }
    if (b2.calculate_item_price() != (3.3 * 1.25 + 1)) {
      cout << "test 2 for burger item price calculation failed, result "
              "unexpected"
           << endl;
    }
  }

  // test case 3 for burger, with multiple ingredient and changing variables
  void test_Burger_case3() {
    // Create a burger with parameters (including multiple ingredients),
    Ingredient i1 = Ingredient("i1", 1);
    Ingredient i2 = Ingredient("i2", 2);
    Ingredient i3 = Ingredient("i3", 3);
    Burger b3 = Burger("burger2", 3.3, 2, "bun1", "meat1", {i1});

    // change the parameters with set functions,
    b3.set_ingredient_list({i1, i2});
    b3.add_ingredient(i3);
    b3.set_burger_bun("bun3");
    b3.set_burger_meat("beef");
    b3.set_item_name("burger3");
    b3.set_item_price(5.5);
    b3.set_item_size("large");

    // compare the parameters, ingredients, and final price against the expected
    // ingredient/price
    if (b3.get_burger_bun() != "bun3") {
      cout << "test 3 for burger bun failed, result unexpected" << endl;
    }
    if (b3.get_burger_meat() != "beef") {
      cout << "test 3 for burger meat failed, result unexpected " << endl;
    }
    if (b3.get_item_name() != "burger3") {
      cout << "test 3 for burger name failed, result unexpected" << endl;
    }
    if (b3.get_item_price() != 5.5) {
      cout << "test 3 for burger price failed, result unexpected" << endl;
    }
    if (b3.get_item_size() != 3) {
      cout << "test 3 for burger size failed, result unexpected" << endl;
    }
    if (b3.get_ingredient(0).get_name() != "i1") {
      cout << "test 3 for burger ingredient 1 name failed, result unexpected"
           << endl;
    }
    if (b3.get_ingredient(0).get_price() != 1) {
      cout << "test 3 for burger ingredient 1 price failed, result unexpected"
           << endl;
    }
    if (b3.get_ingredient(1).get_name() != "i2") {
      cout << "test 3 for burger ingredient 2 name failed, result unexpected"
           << endl;
    }
    if (b3.get_ingredient(1).get_price() != 2) {
      cout << "test 3 for burger ingredient 2 price failed, result unexpected"
           << endl;
    }
    if (b3.get_ingredient(2).get_name() != "i3") {
      cout << "test 3 for burger ingredient 3 name failed, result unexpected"
           << endl;
    }
    if (b3.get_ingredient(2).get_price() != 3) {
      cout << "test 3 for burger ingredient 3 price failed, result unexpected"
           << endl;
    }
    if (b3.calculate_item_price() != (5.5 * 1.5 + 1 + 2 + 3)) {
      cout << "test 3 for burger item price calculation failed, result "
              "unexpected"
           << endl;
    }
  }

 public:
  // run_tests runs the test cases created above.
  void run_tests() {
    test_Burger_default();
    test_Burger_case1();
    test_Burger_case2();
    test_Burger_case3();
  }
};
