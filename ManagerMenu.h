#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

class ManagerMenu {
 private:
  int state_portal_manager =
      0;  // 0 mean no need to run portal again, 1 means need to run again.
 public:
  void run();
  int get_state_portal_manager();
  ManagerMenu();
  ~ManagerMenu();
};

#endif