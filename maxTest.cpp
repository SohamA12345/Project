#include <iostream>

#include <fstream>

#include "Pasta.h"
#include "Pizza.h"

#include "ReadItem.h"



void write_food_item(Pasta pasta) { // pizza
  std::string file_name = pasta.get_item_name() + ".txt";
  std::ofstream outFile(file_name); // make write file object

  outFile << pasta.get_item_name() << std::endl;
  outFile << pasta.get_item_price() << std::endl;
  int item_size_number = pasta.get_item_size();
std::string item_size;
  if (item_size_number == 1) {
        item_size = "small";
    } else if (item_size_number == 2) {
        item_size = "medium";
    } else if (item_size_number == 3) {
        item_size = "large";
    } else {
        cout << "invalid input, size set to small" << endl;
        item_size = "small";
    }
    outFile << item_size << std::endl;
    outFile << pasta.get_pasta_sauce() << std::endl;
    int no_ingredients = pasta.get_ingredient_list().size();
    outFile << no_ingredients << std::endl;
    for (int i = 0; i < no_ingredients; i++) {
      outFile << pasta.get_ingredient(i).get_name() << std::endl;
    }

outFile.close();
}

void write_ingredient_list(vector<Ingredient> list) {
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
  while (std::getline(inFile, current_line)) { // loops while it reads a line
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

Pasta read_pasta_file(std::string name) {
  int ingredients_line_start = 6;
  std::ifstream inFile(name + ".txt");
  // read each line
  int line_count = 0;
  std::string current_line;
  Pasta pasta;
  vector<Ingredient> temp_list = read_ingredient_list();
    vector<Ingredient> curr_list;
  while (std::getline(inFile, current_line)) { // loops while it reads a line
    line_count++;
    if (line_count < ingredients_line_start) {
      switch (line_count)
      {
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
      while (index <  temp_list.size() && was_found == false) {
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

Pizza p;
ReadItem r;
std::string name = "MacandCheese";
p = r.read_pizza(name);


std::cout << p.get_item_name() << std::endl;
std::cout << p.get_item_price() << std::endl;
std::cout << p.get_item_size() << std::endl;

std::cout << p.get_pizza_sauce() << std::endl;
std::cout << p.get_pizza_cheese() << std::endl;

std::cout << p.get_ingredient_list()[0].get_name() << std::endl;
std::cout << p.get_ingredient_list()[0].get_price() << std::endl;
std::cout << p.get_ingredient_list()[1].get_name() << std::endl;
std::cout << p.get_ingredient_list()[1].get_price() << std::endl;
std::cout << p.get_ingredient_list()[2].get_name() << std::endl;
std::cout << p.get_ingredient_list()[2].get_price() << std::endl;


  return 0;
}
