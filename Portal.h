// Portal to enter 

#ifndef PORTAL_H
#define PORTAL_H

class Portal {
 private:
  // 0 mean no need to run portal again, 1 means need to run again.
  int state_portal = 0;  
 public:
  // runs the portal
  void run();

  // returns the current state of portal, 0 or 1
  int get_state_portal();

  // default constructor and destructor
  Portal();
  ~Portal();
};
//To-do
// Change size of food in customer menu
// Drink menu
// Print recipt go to log out page

#endif