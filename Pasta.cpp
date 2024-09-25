#include "Pasta.h"

Pasta::Pasta(std::string name, double price, int size, std::string pastaSauce) : MenuItem(name, price, size), pastaSauce(pastaSauce) {}

Pasta::Pasta() : MenuItem() , pastaSauce("NoSauce"){}

std::string Pasta::get_pastaSauce() {
  return pastaSauce;
}

void Pasta::set_pastaSauce(std::string pastaSauce) {
  this->pastaSauce = pastaSauce;
}