#ifndef MANAGER_DRINK_H
#define MANAGER_DRINK_H

class ManagerDrink {
 private:
  int state_portal_drink = 0;  // 0 mean no need to run portal again, 1 means
                               // need to run again.
 public:
  void run(int& state_portal_food);
  int get_state_portal_drink();
  ManagerDrink(/* args */);
  ~ManagerDrink();
};

#endif