#include "generic_menu.h"

generic_menu::generic_menu() {}

generic_menu::~generic_menu() {}

void generic_menu::menu_head(menu* obj, std::string title) {
  obj->menu_head(title);
}

void generic_menu::options(menu* obj, std::string options_array[], int no_of_options) {
  for (int i = 0; i < no_of_options; i++) {
    obj->add(options_array[i]);
  }
}

int generic_menu::disp(menu* obj) {
  return obj->display();
}

void generic_menu::return_logic(int choice) {
  return;
}