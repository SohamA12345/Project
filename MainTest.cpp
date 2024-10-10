#include "DrinkTest.h"
#include "PizzaTest.h"
#include "PastaTest.h"
// #include "AddToCartTest.h"
// #include "CustomerLoginTest.h"

int main() {

    cout << "This is the test for Drink (no text = no error, everything working as intended): " << endl;
    DrinkTest run_drink;
    run_drink.run_tests();

    cout << "\nThis is the test for Pizza: " << endl;
    PizzaTest run_pizza;
    run_pizza.run_tests();

    cout << "\nThis is the test for Pasta: " << endl;
    PastaTest run_pasta;
    run_pasta.run_tests();


    // AddToCartTest A_T_C_T;
    // A_T_C_T.run_tests();

    // CustomerLoginTest C_L_T;
    // C_L_T.run_tests();

    return 0;
}