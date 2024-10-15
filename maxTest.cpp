#include <fstream>
#include <iostream>

#include "Burger.h"
#include "Chips.h"
#include "Drink.h"
#include "IngredientList.h"
#include "Noodle.h"
#include "Pasta.h"
#include "Pizza.h"
#include "ReadIn.h"
#include "Rice.h"
#include "WriteIn.h"

// void write_food_item(Pasta pasta) {  // pizza
//   std::string file_name = pasta.get_item_name() + ".txt";
//   std::ofstream outFile(file_name);  // make write file object

//   outFile << pasta.get_item_name() << std::endl;
//   outFile << pasta.get_item_price() << std::endl;
//   int item_size_number = pasta.get_item_size();
//   std::string item_size;
//   if (item_size_number == 1) {
//     item_size = "small";
//   } else if (item_size_number == 2) {
//     item_size = "medium";
//   } else if (item_size_number == 3) {
//     item_size = "large";
//   } else {
//     cout << "invalid input, size set to small" << endl;
//     item_size = "small";
//   }
//   outFile << item_size << std::endl;
//   outFile << pasta.get_pasta_sauce() << std::endl;
//   int no_ingredients = pasta.get_ingredient_list().size();
//   outFile << no_ingredients << std::endl;
//   for (int i = 0; i < no_ingredients; i++) {
//     outFile << pasta.get_ingredient(i).get_name() << std::endl;
//   }

//   outFile.close();
// }
/*
void write_ingredient_list(IngredientList ingredient_list) {
  std::vector<Ingredient> list = ingredient_list.get_ingredient_list();
  std::ofstream outFile("ingredientlist.txt");
  int list_length = list.size();
  for (int i = 0; i < list_length; i++) {
    outFile << list[i].get_name() << std::endl;
    outFile << list[i].get_price() << std::endl;
  }
}

vector<Ingredient> read_ingredient_list() {
  std::ifstream inFile("ingredientlist.txt");
  vector<Ingredient> list;
  int line_count = 0;
  std::string current_line;
  int index = 0;
  while (std::getline(inFile, current_line)) {  // loops while it reads a line
    line_count++;
    if (line_count % 2 == 1) {
      list.push_back(Ingredient());
      list[index].set_name(current_line);
    } else {
      list[index].set_price(stod(current_line));
      index++;
    }
  }
  return list;
}
*/ /*
Pasta read_pasta_file(std::string name) {
  int ingredients_line_start = 6;
  std::ifstream inFile(name + ".txt");
  // read each line
  int line_count = 0;
  std::string current_line;
  Pasta pasta;
  vector<Ingredient> temp_list = read_ingredient_list();
  vector<Ingredient> curr_list;
  while (std::getline(inFile, current_line)) {  // loops while it reads a line
    line_count++;
    if (line_count < ingredients_line_start) {
      switch (line_count) {
        case 1:
          pasta.set_item_name(current_line);
          break;
        case 2:
          pasta.set_item_price(stod(current_line));
          break;
        case 3:
          pasta.set_item_size(current_line);
          break;
        case 4:
          pasta.set_pasta_sauce(current_line);
          break;
        default:
          break;
      }
    } else {
      int index = 0;
      bool was_found = false;
      std::cout << current_line << std::endl;
      while (index < temp_list.size() && was_found == false) {
        if (temp_list[index].get_name() == current_line) {
          curr_list.push_back(temp_list[index]);
          was_found = true;
        }

        index++;
      }
      if (was_found == false) {
        curr_list.push_back(Ingredient());
      }
    }
  }
  pasta.set_ingredient_list(curr_list);
  return pasta;
}
*/
int main() {
  //  std::vector<Pizza> pizzaList;

  // temporary
  /*
    std::string input_name;
    double input_price;
    int input_size;
    std::string input_sauce;
    std::string input_base;

    std::cout << "Write pizza to add one ";
    std::string user_input;
    std::getline(std::cin, user_input);
  */
  /*
    if (user_input == "pizza") {
      std::cout << "Enter pizza name: ";
      std::cin.ignore();
      std::getline(std::cin, input_name);
      std::cout << "Enter pizza price ";
      std::cin >> input_price;
      std::cout << "Enter pizza size: ";
      std::cin >> input_size;
      std::cout << "Enter pizza sauce: ";
      std::cin.ignore();
      std::getline(std::cin, input_sauce);
      std::cout << "Enter pizza base: ";
      std::cin.ignore();
      std::getline(std::cin, input_base);
      pizzaList.push_back(
          Pizza(input_name, input_price, input_size, input_sauce, input_base));
    } else if (user_input == "pasta") {
      std::cout << "Please try again." << std::endl;
    } else {
      std::cout << "Please try again." << std::endl;
    }

    std::vector<Ingredient> ingerdientList;

    for (int i = 0; i < 1; i++) {
      std::cout << "Write i to add one: ";
      std::cin >> user_input;
      if (user_input == "i") {
        std::cout << "Enter ingeredient name: ";
        std::string input_name;
        std::cin.ignore();
        std::getline(std::cin, input_name);
        std::cout << "Enter ingredient price ";
        double input_price;
        std::cin >> input_price;
        ingerdientList.push_back(Ingredient(input_name, input_price));
        pizzaList[i].add_ingredient(&ingerdientList[i]);
      } else {
        std::cout << "fail" << std::endl;
      }
    }


    std::cout << pizzaList[0].get_item_name() << std::endl;
    pizzaList[0].print_ingredients_and_price();

  */

  /*
  Pasta p("MacandCheese", 5, 1, "tomato");

  Ingredient i("cheese", 1);
  p.add_ingredient(i);
  Ingredient i2("spring onion", 0.50);
  p.add_ingredient(i2);



  write_food_item(p);
  */

  /*
  vector<Ingredient> ingredient_list;
  Ingredient i("cheese", 1);
  Ingredient i2("spring onion", 0.50);
  Ingredient i3("sassauge", 2.50);
  Ingredient i4("cucumber", 1.25);
  ingredient_list.push_back(i);
  ingredient_list.push_back(i2);
  ingredient_list.push_back(i3);
  ingredient_list.push_back(i4);

  write_ingredient_list(ingredient_list);



  //std::cout << p.get_item_name() << std::endl;

  vector<Ingredient> list = read_ingredient_list();

  Pasta p = read_pasta_file("MacandCheese");

  p.add_ingredient(i4);


  for (int i = 0; i < p.get_ingredient_list().size(); i++) {
  std::cout << p.get_ingredient(i).get_name() << std::endl;
  std::cout << p.get_ingredient(i).get_price() << std::endl;
  }

  write_food_item(p);

  */

  // list.add_ingredient("Curry", 3.00);
  /*
    ReadIn read_in; // create read object

    IngredientList list = read_in.read_ingredient_list(); // reads file called
    ingredientlist.txt and hold the ingredients in list
    list.add_ingredient("Curry", 2.5); // this function will add ingredient with
    input name and price list.add_ingredient("Bacon", 1.5);
    list.remove_ingredient("Curry");  // will remove ingredient by name

    // you can use this to check everything is right
    for (int i = 0; i < list.get_ingredient_list().size(); i++) {
      std::cout << list.get_ingredient_list()[i].get_name() << std::endl;
      std::cout << list.get_ingredient_list()[i].get_price() << std::endl;
    }

    WriteIn write_in; // create write object

    write_in.write_ingredient_list(list); // write back to ingredient.txt ther
    ```hý`` new list after updating

  */
  /*write_ingredient_list(list);


  Burger p;
  ReadItem r;
  std::string name = "MacandCheese";
  p = r.read_burger(name);


  std::cout << p.get_item_name() << std::endl;
  std::cout << p.get_item_price() << std::endl;
  std::cout << p.get_item_size() << std::endl;

  std::cout << p.get_burger_bun() << std::endl;
  std::cout << p.get_burger_meat() << std::endl;

  std::cout << p.get_ingredient_list()[0].get_name() << std::endl;
  std::cout << p.get_ingredient_list()[0].get_price() << std::endl;
  std::cout << p.get_ingredient_list()[1].get_name() << std::endl;
  std::cout << p.get_ingredient_list()[1].get_price() << std::endl;
  std::cout << p.get_ingredient_list()[2].get_name() << std::endl;
  std::cout << p.get_ingredient_list()[2].get_price() << std::endl;
  */

  ReadIn read_in;
  WriteIn write_in;

/*
  std::vector<string> pizza_list = read_in.read_menu_item_list("pizzalist");
  std::vector<string> burger_list = read_in.read_menu_item_list("burgerlist");
  std::vector<string> noodle_list = read_in.read_menu_item_list("noodlelist");
  std::vector<string> chips_list = read_in.read_menu_item_list("chipslist");
  std::vector<string> rice_list = read_in.read_menu_item_list("ricelist");
  std::vector<string> drinks_list = read_in.read_menu_item_list("drinkslist");

  // make the menu item vectors using the string vectors

  std::vector<MenuItem*> obj_pizza_list;
  //   for (int i = 0; i < pizza_list.size(); i++) {
  //       Pizza pizza = read_in.read_pizza(pizza_list[i]);
  //         obj_pizza_list.push_back(&pizza);
  //   }
  std::vector<MenuItem*> obj_burger_list;
  //   for (int i = 0; i < burger_list.size(); i++) {
  //         Burger burger = read_in.read_burger(burger_list[i]);
  //         obj_burger_list.push_back(&burger);
  //   }

  std::vector<MenuItem*> obj_noodle_list;
  //   for (int i = 0; i < noodle_list.size(); i++) {
  //         Noodle noodle = read_in.read_noodle(noodle_list[i]);
  //         obj_noodle_list.push_back(&noodle);
  //   }
  std::vector<MenuItem*> obj_chips_list;
  //   for (int i = 0; i < chips_list.size(); i++) {
  //     Chips chips = read_in.read_chips(chips_list[i]);
  //         obj_chips_list.push_back(&chips);
  //   }

  std::vector<MenuItem*> obj_rice_list;
  //   for (int i = 0; i < rice_list.size(); i++)
  //   {
  //     Rice rice = read_in.read_rice(rice_list[i]);
  //         obj_rice_list.push_back(&rice);
  //   }

  std::vector<MenuItem*> obj_drinks_list;
  //   for (int i = 0; i < drinks_list.size(); i++) {
  //     Drink drink = read_in.read_drink(drinks_list[i]);
  //         obj_drinks_list.push_back(&drink);
  //   }

  Pizza p("PizzaTest2", 1, 1, "SauceTest", "CheeseTest");  // create object
  write_in.write_pizza(p);  // create own txt file
  obj_pizza_list.push_back(&p);
  write_in.write_menu_item_list(obj_pizza_list, "pizzalist");
  Burger b("BurgerTest2", 1, 1, "BunTest", "meatTest");  // create object
  write_in.write_burger(b);                              // create own txt file
  obj_burger_list.push_back(&b);
  write_in.write_menu_item_list(obj_burger_list, "burgerlist");
  Noodle n("NoodleTst", 1, 1, "typetest", "souptest");  // create object
  write_in.write_noodle(n);                             // create own txt file
  obj_noodle_list.push_back(&n);
  write_in.write_menu_item_list(obj_noodle_list, "noodlelist");
  Chips c("Chipstest", 2, 3, "cuttest", "seasoningtest");  // create object
  write_in.write_chips(c);  // create own txt file
  obj_chips_list.push_back(&c);
  write_in.write_menu_item_list(obj_chips_list, "chipslist");
  Rice r("ricetest", 234, 2, "typetest");  // create object
  write_in.write_rice(r);                  // create own txt file
  obj_rice_list.push_back(&r);
  write_in.write_menu_item_list(obj_rice_list, "ricelist");
  Drink d(1, "drinktest", 2.50);  // create object
  write_in.write_drink(d);        // create own txt file
  obj_drinks_list.push_back(&d);
  write_in.write_menu_item_list(obj_drinks_list, "drinksist");

*/
/*
std::vector<string> pasta_list = read_in.read_menu_item_list("pastalist");

Pasta pasta = read_in.read_pasta(pasta_list[0]);

std::cout << pasta.get_item_name() << std::endl;

for (int i = 0; i < pasta.get_ingredient_list().size(); i++) {
  std::cout << pasta.get_ingredient_list()[i].get_name() << " " << pasta.get_ingredient_list()[i].get_price() << endl;
}
*/

  //Pasta pasta("Banana juice", 10.0, 1, "tubes", "tomato");
  // IngredientList list = read_in.read_ingredient_list();
  // Ingredient ingredient1("Meatballs", 2.0);
  // list.add_ingredient(ingredient1);
  // pasta.add_ingredient(ingredient1);
  // write_in.write_ingredient_list(list);

  //write_in.create_pasta(pasta);

//write_in.remove_pasta("Spagetti");

// Drink drink(1, "Coke", 3.50, 1, false);

//   write_in.create_drink(drink);

  /*
  ReadIn read_in;
  std::string file_name = "drinklist";
  std::vector<string> drink_list = read_in.read_menu_item_list(file_name);

  for (int i = 0; i < drink_list.size(); i++) {
  std::cout << drink_list[i] << std::endl;
  }

  WriteIn write_in;

  write_in.write_menu_item_list

  drink_list.push_back("Fanta");


  write_in.write_menu_item_list(drink_list, "drinklist");
  */
  return 0;
}
