#include "CustomerFoodDrink.h"
#include "MMaker.h"
#include "Checkout.h"
#include "CustomerCategoriesFood.h"

void CustomerFoodDrink::run(int& state_customer_login) {
  menu CustomerFoodDrink;
  string cart_content = "";
  int total_price = 0;

  CustomerFoodDrink.menu_head("What do you want to order today?");

  for(int i = 0; i < cart.size(); i++) {
    cart_content += cart[i]->get_item_name();
    total_price += cart[i]->calculate_item_price();
  }

  CustomerFoodDrink.add("Food", 1, "Wide range of cuisines categorised under Burger, Chips, Noodles, Pasta, Pizza, Rice.");
  CustomerFoodDrink.add("Drink", 2, "Drinks Menu");
  CustomerFoodDrink.add("Check-out", 3, cart_content); //cart_content + '\t' + to_string(total_price)
  CustomerFoodDrink.add("Log-out", 4, "Returns to the login page.");

  int choice = CustomerFoodDrink.display();

  Checkout obj;
  CustomerCategoriesFood obj1;

  switch (choice)
  {
  case 1:
    
    do
    {
      obj1.run(this->state_customer);
    } while (obj1.get_state_categories() == 1);

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

      cart.clear();

      return;
    break;
  case 5:
  // clears cart.
  default:
    break;
  }
}

int CustomerFoodDrink::get_state_customer() {return this->state_customer;}

CustomerFoodDrink::CustomerFoodDrink() {}
CustomerFoodDrink::~CustomerFoodDrink() {}