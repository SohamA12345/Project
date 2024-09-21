#ifndef GENERIC_MENU
#define GENERIC_MENU

// Abstract class to help create any menu in this project.

#include "mmaker.h"

class generic_menu
{
private:
  menu menu;
  int customer_choices;
public:
  generic_menu();
  ~generic_menu();

  virtual void menu_head(string title) = 0;
  virtual void options(string options_array[], int no_of_options) = 0; //If this is manager menu we can use this to add options in the food.
  virtual int disp() = 0;
};

#endif