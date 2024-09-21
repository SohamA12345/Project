// This implements a menu for the
#include <fstream>
#include <iostream>
#include <string>

#include "mmaker.h"
#include "portal.h"

int main() {
  portal portal_obj;

  do
  {
    portal_obj.run();
  } while (portal_obj.get_state() == 1);
  

  return 0;
}