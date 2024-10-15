#ifndef MANAGER_DRINK_H
#define MANAGER_DRINK_H

class ManagerDrink {
 private:
  int state_portal_drink = 0;  // 0 mean no need to run portal again, 1 means
                               // need to run again.
 public:
  // runs portal
  void run(int& state_portal_food);

  // gets the state_portal_drink (returns 0 or 1)
  int get_state_portal_drink();

  // default constructor and destructor
  ManagerDrink(/* args */);
  ~ManagerDrink();
};

#endif