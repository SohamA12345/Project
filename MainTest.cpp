#include "DrinkTest.h"
#include "PizzaTest.h"
#include "PastaTest.h"
#include "NoodleTest.h"
#include "RiceTest.h"
#include "ChipsTest.h"
#include "BurgerTest.h"
// #include "AddToCartTest.h"
// #include "CustomerLoginTest.h"

int main() {
    cout << "This is the main testing file. If there are no words after a test, the test is successful and there's no error.\n" << endl;

    // test for drink
    cout << "This is the test for Drink: " << endl;
    DrinkTest run_drink;
    run_drink.run_tests();

    // test for pizza
    cout << "\nThis is the test for Pizza: " << endl;
    PizzaTest run_pizza;
    run_pizza.run_tests();

    // test for pasta
    cout << "\nThis is the test for Pasta: " << endl;
    PastaTest run_pasta;
    run_pasta.run_tests();

    // test for noodle
    cout << "\nThis is the test for Noodle: " << endl;
    NoodleTest run_noodle;
    run_noodle.run_tests();

    // test for rice
    cout << "\nThis is the test for Rice: " << endl;
    RiceTest run_rice;
    run_rice.run_tests();

    // test for chips
    cout << "\nThis is the test for Chips: " << endl;
    ChipsTest run_chips;
    run_chips.run_tests();

    // test for burger
    cout << "\nThis is the test for Burgers: " << endl;
    BurgerTest run_Burger;
    run_Burger.run_tests();

    // AddToCartTest A_T_C_T;
    // A_T_C_T.run_tests();

    // CustomerLoginTest C_L_T;
    // C_L_T.run_tests();

    return 0;
}