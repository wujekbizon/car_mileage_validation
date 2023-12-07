#include <iostream>
#include "./include/UI.h"
#include "./include/Car.h"
#include "./nlohmann/json.hpp"

using json = nlohmann::json;

int main()
{
  UI ui;
  Car car("Toyota", "Corolla", 2003, 100000, "Gasoline", 20000.00, "Japan", "Automatic", "Front-wheel drive", false, 1, std::vector<std::string>{"John Doe", "Jane Doe"});
  json carJSON = car.toJSON();

  std::cout << carJSON.dump(4) << std::endl;
  ui.displayWelcomeMessage();
  return 0;
}