#include <iostream>
#include <string>
#include<vector>

class Ingredient {
  private:
    std::string name;
    double price;
  public:

  Ingredient(double price, std::string name) : price(price), name(name) {}

  std::string get_name() {
      return name;
  }

};



class Pasta {
  private:
    double price;
    std::string name;
    std::vector<Ingredient*> ingredientList;

    // pasta exclusive
    std::string pastaSauce;

  public:

  Pasta() : price(9999999), name("NoName"), pastaSauce("No Sauce")  {}

  Pasta(double price, std::string name, std::string pastaSauce) : price(price), name(name), pastaSauce(pastaSauce) {}

  void addIngredient(Ingredient &i) {
    ingredientList.push_back(&i);
  }

  Ingredient* get_ingredient(int index) {
    return ingredientList[index];
  }

  std::string get_ingredientName(int index) {
      return get_ingredient(index)->get_name();
  }

};


int main() {

Ingredient tomato(2.0, "Tomato");
Ingredient mushroom(2.0, "Mushroom");
Ingredient onion(2.0, "Onion");

<<<<<<< HEAD
Pasta yummy(7.5, "Yummy", "Tomato Sauce");

yummy.addIngredient(tomato);
yummy.addIngredient(mushroom);
yummy.addIngredient(onion);

  std::cout << yummy.get_ingredientName(2) << std::endl;
=======
};
>>>>>>> 6c202bd4525764aa4a9f80ee49fadf25817bb877

  return 0;
}