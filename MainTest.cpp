#include "DrinkTest.h"
#include "PizzaTest.h"
#include "PastaTest.h"
#include "NoodleTest.h"
// #include "AddToCartTest.h"
// #include "CustomerLoginTest.h"

int main() {
    cout << "This is the main testing file. If there are no words after a test, the test is successful and there's no error.\n" << endl;

    cout << "This is the test for Drink: " << endl;
    DrinkTest run_drink;
    run_drink.run_tests();

    cout << "\nThis is the test for Pizza: " << endl;
    PizzaTest run_pizza;
    run_pizza.run_tests();

    cout << "\nThis is the test for Pasta: " << endl;
    PastaTest run_pasta;
    run_pasta.run_tests();

    cout << "\nThis is the test for Noodle: " << endl;
    NoodleTest run_noodle;
    run_noodle.run_tests();

    // AddToCartTest A_T_C_T;
    // A_T_C_T.run_tests();

    // CustomerLoginTest C_L_T;
    // C_L_T.run_tests();

    return 0;
}