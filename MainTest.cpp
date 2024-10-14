#include "DrinkTest.h"
#include "PizzaTest.h"
#include "PastaTest.h"
#include "NoodleTest.h"
#include "RiceTest.h"
#include "ChipsTest.h"
#include "BurgerTest.h"

int main() {
    cout << "This is the main testing file. If there are no words after a test, the test is successful and there's no error.\n" << endl;

    // test for drink
    cout << "This is the test for Drink: (passed if nothing) " << endl;
    DrinkTest run_drink;
    run_drink.run_tests();

    // test for pizza
    cout << "\nThis is the test for Pizza: (passed if nothing)" << endl;
    PizzaTest run_pizza;
    run_pizza.run_tests();

    // test for pasta
    cout << "\nThis is the test for Pasta: (passed if nothing)" << endl;
    PastaTest run_pasta;
    run_pasta.run_tests();

    // test for noodle
    cout << "\nThis is the test for Noodle: (passed if nothing)" << endl;
    NoodleTest run_noodle;
    run_noodle.run_tests();

    // test for rice
    cout << "\nThis is the test for Rice: (passed if nothing)" << endl;
    RiceTest run_rice;
    run_rice.run_tests();

    // test for chips
    cout << "\nThis is the test for Chips: (passed if nothing)" << endl;
    ChipsTest run_chips;
    run_chips.run_tests();

    // test for burger
    cout << "\nThis is the test for Burger: (passed if nothing)" << endl;
    BurgerTest run_Burger;
    run_Burger.run_tests();

    return 0;
}