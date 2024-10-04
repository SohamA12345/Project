#ifndef WRITE_IN_H
#define WRITE_IN_H

#include <fstream>

#include "IngredientList.h"


class WriteIn {
  private:

  public:
  // default constructor
  WriteIn();

  // write to ingredient list text file
  void write_ingredient_list(IngredientList ingredient_list);

  // deconstructor
  ~WriteIn();
};

#endif