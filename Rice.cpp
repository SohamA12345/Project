#include "Rice.h"

// default constructor
Rice::Rice() : FoodItem(), rice_type("N/A") {}

// constructor without ingredients
Rice::Rice(std::string name, double price, int size, std::string rice_type)
    : FoodItem(name, price, size), rice_type(rice_type) {}

// constructor with ingredients
Rice::Rice(std::string name, double price, int size, std::string rice_type,
           std::vector<Ingredient> ingredients)
    : FoodItem(name, price, size, ingredients), rice_type(rice_type) {}

// getter functions
std::string Rice::get_rice_type() { return rice_type; }

// setter functions
void Rice::set_rice_type(std::string rice_type) { this->rice_type = rice_type; }

// deconstructor
Rice::~Rice() {}