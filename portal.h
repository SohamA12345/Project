#ifndef PORTAL_H
#define PORTAL_H

#include "mmaker.h"

class portal {
  private:
  int state = 0; // 0 mean no need to run portal again, 1 means need to run again.
 public:
  void run();
  int get_state();
};

#endif