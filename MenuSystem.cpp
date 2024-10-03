// Main File to display the starting gui.

#include "Portal.h"

int main() {
  Portal portal_obj;
  
  do
  {
    portal_obj.run();
  } while (portal_obj.get_state_portal() == 1);
  
  return 0;
}