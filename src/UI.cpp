#include <iostream>
#include <string>
#include "./include/UI.h"

void UI::displayWelcomeMessage()
{
  std::cout << "Welcome to the Car Mileage Validation Application" << std::endl;
  std::cout << "------------------------------------------------" << std::endl;
}

void UI::promptForVIN()
{
  std::string vin;
  std::cout << "Enter the car's VIN: ";
  readUserInput(vin);
}

void UI::promptForModelYear()
{
  std::string modelYear;
  std::cout << "Enter the car's model year: ";
  readUserInput(modelYear);
}

void UI::promptForOdometerReading()
{
  std::string odometerReading;
  std::cout << "Enter the car's odometer reading: ";
  readUserInput(odometerReading);
}

void UI::displayValidationResult(bool isOriginalMileage)
{
  if (isOriginalMileage)
  {
    std::cout << "The car's mileage is likely original." << std::endl;
  }
  else
  {
    std::cout << "The car's mileage may be tampered with." << std::endl;
  }
}

void UI::readUserInput(std::string &input)
{
  std::cin >> input;
}
