#include "AddIngredient.h"
#include "MMaker.h"


void AddIngredient::run(int& state_portal_food) {
  menu AddIngredient;

  AddIngredient.menu_head("Ingredients Toolkit");

  AddIngredient.add("Add Ingredient", 1, "Add a new ingredient used to create unique dishes");
  AddIngredient.add("Remove Ingredient", 2, "Removes a certain ingredient from all the dishes created and ingredient list. No way to recover the ingredient.");
  AddIngredient.add("Show all ingredients", 3, "Displays all the ingredient that were created and still available.");
  AddIngredient.add("Back", 4, "Returns to Menu Changing Suite");

  int choice = AddIngredient.display();

  switch (choice)
  {
  case 1:
    /* code */
    break;
  
  default:
    break;
  }
}

int AddIngredient::get_add_ingredient() {return this->add_ingredient;}

AddIngredient::AddIngredient() {}

AddIngredient::~AddIngredient() {}