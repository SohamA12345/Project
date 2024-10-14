// Main File to display the starting gui.

#include "Portal.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

int main() {
  // create a portal, then runs it while the state of portal is = 1
  Portal portal_obj;
  
  do
  {
    portal_obj.run();
  } while (portal_obj.get_state_portal() == 1);
  
  return 0;
}