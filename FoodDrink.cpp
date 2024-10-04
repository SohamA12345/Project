#include "FoodDrink.h"
#include "MMaker.h"

void FoodDrink::run(int& state_portal_manager) {
  menu FoodDrink;

  FoodDrink.menu_head("Menu Changing Suite");
  FoodDrink.add("Ingredients", 1, "Use this to create a ingredient which can be used in new dish.");
  FoodDrink.add("Food", 2, "Use ingredient, and various factors to create unique dishes from a base food type.");
  FoodDrink.add("Drink", 3, "Create a new drink in the menu.");
  FoodDrink.add("Back", 4, "Return to Manager Tools");

  int choice = FoodDrink.display();

  switch (choice)
  {
  case 1:
    break;

  case 2:
    break;

  case 3:
    break;

  case 4:
  
    this->state_portal_food = 0;
    state_portal_manager = 1;

    return;
  default:
    break;
  }
}

int FoodDrink::get_state_portal_food() {return this->state_portal_food;}

FoodDrink::FoodDrink() {}
FoodDrink::~FoodDrink() {}