#ifndef PASTA_H
#define PASTA_H

#include "MenuItem.h"

  class Pasta : public MenuItem{
    private:
      std::string pastaSauce;
    public:

    Pasta(std::string name, double price, int size, std::string pastaSauce);

    Pasta();

    std::string get_pastaSauce();

    void set_pastaSauce(std::string pastaSauce);

  };

#endif