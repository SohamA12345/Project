#include "CustomerFoodDrink.h"
#include "MMaker.h"
#include "Checkout.h"

void CustomerFoodDrink::run(int& state_customer_login) {
  menu CustomerFoodDrink;

  CustomerFoodDrink.menu_head("What do you want to order today?");

  CustomerFoodDrink.add("Food", 1, "Wide range of cuisines categorised under Burger, Chips, Noodles, Pasta, Pizza, Rice.");
  CustomerFoodDrink.add("Drink", 2, "Drinks Menu");
  CustomerFoodDrink.add("Check-out", 3, "//Shows your cart.");
  CustomerFoodDrink.add("Log-out", 4, "Returns to the login page.");

  int choice = CustomerFoodDrink.display();

  Checkout obj;

  switch (choice)
  {
  case 1:
    //Food

    break;
  case 2:
    //Drink

    break;
  case 3:
    //Check-out
    do
    {
      obj.run(this->state_customer);
    } while (obj.get_state_checkout() == 1);
    
    break;
  case 4:
      this->state_customer = 0;
      state_customer_login = 1;

      return;
    break;
  default:
    break;
  }
}

int CustomerFoodDrink::get_state_customer() {return this->state_customer;}

CustomerFoodDrink::CustomerFoodDrink() {}
CustomerFoodDrink::~CustomerFoodDrink() {}