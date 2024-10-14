#include "Checkout.h"

#include <cstdlib>
#include <ctime>

#include "MMaker.h"

void Checkout::run(int& state) {
  srand(time(NULL));
  int code = rand();

  menu Checkout;

  Checkout.menu_head("Remove an item from cart by pressing ENTER on it");

  // loop to create ingredients for each item
  for (int i = 0; i < cart.size(); i++) {
    string ingredient;
    for (int j = 0; j < cart[i].get_ingredient_list().size(); j++) {
      ingredient += cart[i].get_ingredient_list()[j].get_name() + " | ";
    }

    Checkout.add(cart[i].get_item_name(), i,
                 "Price: " + to_string(cart[i].calculate_item_price()) +
                     "\nIngredients: " + ingredient);
  }

  Checkout.add("Proceed/Back", code, "Continue checking out.");

  int choice = Checkout.display();

  if (choice > -1 && cart.size() > 0 && choice != code) {
    cart.erase(cart.begin() + choice);
    this->state_checkout = 1;
    return;

  } else if (choice = code) { 
    // checking out
    if (cart.size() > 0) {
      menu code_menu;

      code_menu.menu_head("Give this code to counter to get food and pay:" +
                          to_string(code));

      code_menu.add("Print code", 1, "Prints the above code and returns to previous file");
      code_menu.add("Back", 2, "Returns to food or drink page");

      int choice = code_menu.display();

      // print receipt/ go back
      switch (choice) {
        case 1:

          this->state_checkout = 0;
          this->state_customer_login = 1;

          cout << "Recipt Printed! Press enter to continue";
          cin.get();

          break;
        case 2:

          this->state_checkout = 0;
          this->state_customer_login = 1;

          return;
        default:
          break;
      }
    } else {
      state = 1;
      this->state_checkout = 0;
      return;
    }
  }
}

int Checkout::get_state_checkout() { return this->state_checkout; }

Checkout::Checkout() {}
Checkout::~Checkout() {}