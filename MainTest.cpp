#include "DrinkTest.h"
#include "AddToCartTest.h"
#include "CustomerLoginTest.h"


int main() {
    DrinkTest D_T;
    D_T.run_tests();

    AddToCartTest A_T_C_T;
    A_T_C_T.run_tests();

    CustomerLoginTest C_L_T;
    C_L_T.run_tests();

    return 0;
}