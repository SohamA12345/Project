#include "ManagerDrink.h"
#include <limits>
#include "Drink.h"
#include "ManagerMenu.h"
#include "WriteIn.h"

void ManagerDrink::run(int& state_portal_food) {
  system("clear");

  string name;
  double price;
  char size;
  int size_int;
  int sugar;
  bool ice;

  cout << "Name of drink: ";

  getline(cin, name);

  while (true) {
    cout << "Price: ";
    cin >> price;

    if (cin.fail()) {
      cin.clear();  // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // ignore invalid input
      cout << "Invalid input. Please enter a numeric value for the "
              "price.\n";
    } else {
      break;  // valid input
    }
  }

  system("clear");

  while (true) {
    cout << "Size (S for small, M for medium, L for large): ";
    cin >> size;

    if (size == 'S') {
      size_int = 1;
      break;
    } else if (size == 'M') {
      size_int = 2;
      break;
    } else if (size == 'L') {
      size_int = 3;
      break;
    } else {
      cout << "Invalid input. Please enter a valid charecter for size.\n";
    }
  }

  while (true) {
    cout << "Sugar (No. of scoops): ";
    cin >> sugar;

    if (cin.fail()) {
      cin.clear();  // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // ignore invalid input
      cout << "Invalid input. Please enter a numeric value for the "
              "price.\n";
    } else {
      break;  // valid input
    }
  }

    while (true) {
    cout << "Ice (true then enter 1 or false then enter 0): ";
    cin >> ice;

    if (cin.fail()) {
      cin.clear();  // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // ignore invalid input
      cout << "Invalid input. Please enter a numeric value for the "
              "price.\n";
    } else {
      break;  // valid input
    }
  }

  Drink obj(size_int, name, price, sugar, ice);

  WriteIn obj2;

  obj2.create_drink(obj);


  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Successfully created an pasta dish. Press ENTER to return.";
  cin.get();

  state_portal_food = 1;

  return;
}

int ManagerDrink::get_state_portal_drink() { return this->state_portal_drink; }

ManagerDrink::ManagerDrink() {}
ManagerDrink::~ManagerDrink() {}