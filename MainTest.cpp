#include "DrinkTest.h"
#include "PizzaTest.h"
#include "AddToCartTest.h"
#include "CustomerLoginTest.h"

int main() {

    cout << "This is the test for Drink: " << endl;
    DrinkTest D_T;
    D_T.run_tests();

    cout << "\nThis is the test for pizza: " << endl;
    PizzaTest P_T;
    P_T.run_tests();

    // AddToCartTest A_T_C_T;
    // A_T_C_T.run_tests();

    // CustomerLoginTest C_L_T;
    // C_L_T.run_tests();

    return 0;
}