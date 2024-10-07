#include "CategoriesFood.h"
#include "MMaker.h"
void CategoriesFood::run(int& state_portal_food) {
  menu CategoriesFood;

  CategoriesFood.menu_head("What type of food is required to be created?");

  CategoriesFood.add("Pasta", 1, "");
  CategoriesFood.add("Chips", 2, "");
  CategoriesFood.add("Pizza", 3, "");
  CategoriesFood.add("Rice", 4, "");
  CategoriesFood.add("Noodle", 5, "");
  CategoriesFood.add("Burger", 6, "");
  CategoriesFood.add("Back", 7, "Returns to Menu Updating Suite");

  int choice = CategoriesFood.display();

  switch (choice)
  {
  case 1:
    //Pasta
    break;
  case 7:
    this->state_categories_food = 0;
    state_portal_food = 1;

    return;
  default:
    break;
  }
}

int CategoriesFood::get_state_categories_food() {return this->state_categories_food;}

CategoriesFood::CategoriesFood() {}
CategoriesFood::~CategoriesFood() {}