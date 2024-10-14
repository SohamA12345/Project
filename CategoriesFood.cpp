#include "CategoriesFood.h"
#include "Pasta.h"
#include "MMaker.h"
#include "WriteIn.h"
#include "ReadIn.h"

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
    {
    //Pasta
    // ask for name, price, size, special ones
    Pasta obj("boo", 2.50, 1, "black", "black");

    Ingredient goo("lemon", 1.00);
    obj.add_ingredient(goo);

    WriteIn obj2;

    ReadIn obj3;

    obj2.write_pasta(obj);

    vector<string> obj4 = obj3.read_menu_item_list("pastalist");

    obj4.push_back(obj.get_item_name());

    obj2.write_menu_item_list(obj4, "pastalist");

    cout << "Readched here";
    cin.get();

    }

    break;
  case 2:
    //Chips

    break;
  case 3:
    //Pizza

    break;
  case 4:
    //Rice

    break;
  case 5:
    //Noodle

    break;
  case 6:
    //Burger

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