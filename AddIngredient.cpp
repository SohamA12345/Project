#include "AddIngredient.h"

#include <limits>

#include "Ingredient.h"
#include "IngredientList.h"
#include "MMaker.h"
#include "ReadIn.h"
#include "WriteIn.h"

void AddIngredient::run(int& state_portal_food) {
  menu AddIngredient;

  AddIngredient.menu_head("Ingredients Toolkit");

  AddIngredient.add("Add Ingredient", 1,
                    "Add a new ingredient used to create unique dishes");
  AddIngredient.add("Remove Ingredient", 2,
                    "Removes a certain ingredient from all the dishes created "
                    "and ingredient list. No way to recover the ingredient.");
  AddIngredient.add(
      "Show all ingredients", 3,
      "Displays all the ingredient that were created and still available.");
  AddIngredient.add("Removes all ingredients. CANNOT Recover content", 4,
                    "Removes all ingredient created.");
  AddIngredient.add("Back", 5, "Returns to Menu Changing Suite");

  int choice = AddIngredient.display();

  WriteIn write_in;  // create write object
  ReadIn read_in;    // create read object

  IngredientList list =
      read_in.read_ingredient_list();  // reads file called ingredientlist.txt
                                       // and hold the ingredients in list

  string ingredient_name;
  double ingredient_price;

  switch (choice) {
    case 1:

      cout << "Enter name of the ingredient: ";
      getline(cin, ingredient_name);

      cout << "Enter price of the ingredient: ";
      cin >> ingredient_price;

      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input! Press ENTER to continue." << endl;
        cin.get();

        this->add_ingredient = 1;

        return;
      }

      list.add_ingredient(ingredient_name,
                          ingredient_price);  // Adds ingredient with from the
                                              // inputs, name and price.
      write_in.write_ingredient_list(
          list);  // write back to ingredient.txt the new list after updating

      cout << "Successfully added Ingredient. Press ENTER to continue.";
      cin.get();

      this->add_ingredient = 1;

      break;
    case 2:
      cout << "Enter name of the ingredient to remove (irreversible): ";
      getline(cin, ingredient_name);

      list.remove_ingredient(
          ingredient_name);  // Removes ingredient by name of it

      write_in.write_ingredient_list(list);  // Updates file.

      cout << "Successfully removed Ingredient. Press ENTER to continue.";
      cin.get();

      this->add_ingredient = 1;

      break;
    case 3:

      // Shows all the ingreadients
      for (int i = 0; i < list.get_ingredient_list().size(); i++) {
        cout << list.get_ingredient_list()[i].get_name() << '\t'
             << list.get_ingredient_list()[i].get_price() << endl;
      }

      cout << "Press ENTER to continue.";
      cin.get();

      this->add_ingredient = 1;

      break;
    case 4:

    {
      ofstream file("ingredientlist.txt", std::ios::trunc);

      if (file.is_open()) {
        file.close();
      } else {
        cout << "Unable to open file";
      }
    }

      cout << "Successfully removed all ingredients. Press ENTER to continue.";
      cin.get();

      this->add_ingredient = 1;

      break;
    case 5:

      this->add_ingredient = 0;
      state_portal_food = 1;

      return;
    default:
      break;
  }
}

int AddIngredient::get_add_ingredient() { return this->add_ingredient; }

AddIngredient::AddIngredient() {}

AddIngredient::~AddIngredient() {}