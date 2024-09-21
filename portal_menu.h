#ifndef PORTAL_MENU_H
#define PORTAL_MENU_H

#include "generic_menu.h"

using namespace std;

class portal_menu : public generic_menu
{
private:
  menu portal;
  string portal_options[3] = {"Manager", "Customer", "Exit"};
public:
  void return_logic(int choice);

  portal_menu();
  ~portal_menu();
};

#endif