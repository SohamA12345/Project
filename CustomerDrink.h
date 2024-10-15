#ifndef CUSTOMER_DRINKS_H
#define CUSTOMER_DRINKS_H

class CustomerDrink {
 private:
  int state_drink;
<<<<<<< HEAD

 public:
=======
public:
  // runs the portal
>>>>>>> f194919595e501686a4ef7ecdc319f9f4125fa46
  void run(int& state_customer);

  // get the value of state_drink (0 or 1)
  int get_state_drink();

  // default constructor/destructor
  CustomerDrink();
  ~CustomerDrink();
};

#endif