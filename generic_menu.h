#ifndef GENERIC_MENU
#define GENERIC_MENU

// Abstract class to help create any menu in this project.

#include "mmaker.h"

class generic_menu : public menu
{
public:
  generic_menu();
  ~generic_menu();

  void menu_head(menu* obj, std::string title);
  void options(menu* obj, std::string options_array[], int no_of_options); //If this is manager menu we can use this to add options in the food.
  int disp(menu* obj);
  virtual void return_logic(int choice) = 0;
};

#endif