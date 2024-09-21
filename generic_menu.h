#ifndef GENERIC_MENU
#define GENERIC_MENU

// Abstract class to help create any menu in this project.

#include "mmaker.h"

class generic_menu : public menu
{
private:
  menu customer;
  int customer_choices;
public:
  generic_menu();
  ~generic_menu();

  virtual void menu_head() = 0;
  virtual void options() = 0; //If this is manager menu we can use this to add options in the food.
  virtual void disp() = 0;
};

#endif