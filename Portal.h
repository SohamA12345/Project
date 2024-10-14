// Portal to enter 

#ifndef PORTAL_H
#define PORTAL_H

class Portal {
 private:
  int state_portal =
      0;  // 0 mean no need to run portal again, 1 means need to run again.
 public:
  void run();
  int get_state_portal();
  Portal();
  ~Portal();
};
//To-do
// Change size of food in customer menu
// Drink menu
// Print recipt go to log out page

#endif