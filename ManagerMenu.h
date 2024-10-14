#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

class ManagerMenu {
 private:
  // 0 mean no need to run portal again, 1 means need to run again.
  int state_portal_manager = 0;

 public:
  // runs the portal
  void run(int& state_portal);

  // gets the state of portal manager, returns 1 if running, 0 if not. 
  int get_state_portal_manager();

  // default constructor and destructor
  ManagerMenu();
  ~ManagerMenu();
};

#endif