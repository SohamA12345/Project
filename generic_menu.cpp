#include "generic_menu.h"

generic_menu::generic_menu() {}

generic_menu::~generic_menu() {}

void generic_menu::menu_head(string title) {
  menu.menu_head(title);
}

void generic_menu::options(string options_array[], int no_of_options) {
  for (int i = 0; i < no_of_options; i++) {
    menu.add(options_array[i]);
  }
}

int generic_menu::disp() {
  return menu.display();
}