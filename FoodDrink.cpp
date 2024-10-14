#include "FoodDrink.h"
#include "MMaker.h"
#include "AddIngredient.h"
#include "CategoriesFood.h"
#include "ManagerDrink.h"

void FoodDrink::run(int& state_portal_manager) {
  menu FoodDrink;

  // add ingredient/food/drink to the menu
  FoodDrink.menu_head("Menu Updating Suite");
  FoodDrink.add("Ingredients", 1, "Use this to create a ingredient which can be used in new dish.");
  FoodDrink.add("Food", 2, "Use ingredient, and various factors to create unique dishes from a base food type.");
  FoodDrink.add("Drink", 3, "Create a new drink in the menu.");
  FoodDrink.add("Back", 4, "Return to Manager Tools");

  int choice = FoodDrink.display();

  AddIngredient obj1;
  CategoriesFood obj2;
  ManagerDrink obj3;

  switch (choice)
  {
  // case 1 goes to add ingredient
  case 1:
    
    do
    {
      obj1.run(this->state_portal_food);
    } while (obj1.get_add_ingredient() == 1);
    
    break;
  // case 2 goes to add food
  case 2:
    do
    {
      obj2.run(this->state_portal_food);
    } while (obj2.get_state_categories_food() == 1);

    break;
  // case 3 goes to add drink
  case 3:
    break;
  // case 4 goes back
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