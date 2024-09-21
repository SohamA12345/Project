#include "portal_menu.h"

void portal_menu::return_logic(int portal_choice) {
  switch (portal_choice) {
    case 1:
      std::cout << "Customer\n";
      break;
    case 2:
      std::cout << "Manager\n";
      break;
    case 3:
      std::cout << "Exit\n";
      return;
    default:
      std::cout << "Invalid selection.\n";
      break;
  }
}

portal_menu::portal_menu() {
  generic_menu::menu_head(portal, "Portal");
  generic_menu::options(portal, portal_options, 3);

  int choices = generic_menu::disp(portal);

  return_logic(choices);
}

portal_menu::~portal_menu() {}