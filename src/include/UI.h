#include "Car.h"
#include <iostream>
/*
This preprocessor directive checks if the macro UI_H is defined.
If it is not defined, then the preprocessor will continue processing
the code that follows.
*/
#ifndef UI_H
/*
This preprocessor directive defines the macro UI_H. Once this macro is defined,
the preprocessor will skip the rest of the code that is enclosed within the
#ifndef and #endif preprocessor directives.
*/
#define UI_H

class UI
{
  private:
    // Gathers car data from the user, calling appropriate prompt functions based on the attribute's type
    void gatherCarData(CarData::Attribute &attribute);

  public:
    // Displays a welcome message to the user
    void displayWelcomeMessage();
    // Prompts the user for the VIN (Vehicle Identification Number) and stores it in the provided `vin` variable
    void promptForVIN(CarData::Attribute &attribute, std::string &vin);

    // Prompts the user for an integer value for the specified CarData::Attribute and stores it in the provided `value`
    // variable
    void promptForIntAttribute(CarData::Attribute &attribute, int &value) const;

    // Prompts the user for a double-precision floating-point value for the specified CarData::Attribute and stores it
    // in the provided `value` variable
    void promptForDoubleAttribute(CarData::Attribute &attribute, double &value) const;

    // Prompts the user for a string value for the specified CarData::Attribute and stores it in the provided `value`
    // variable
    void promptForStringAttribute(CarData::Attribute &attribute, std::string &value) const;

    // Prompts the user for a vector of string values for the specified CarData::Attribute and stores it in the provided
    // `value` variable
    void promptForVectorAttribute(CarData::Attribute &attribute, std::vector<std::string> &value) const;

    // Prompts the user for a boolean value for the specified CarData::Attribute and stores it in the provided `value`
    // variable
    void promptForBoolAttribute(CarData::Attribute &attribute, bool &value) const;

    // Prompts the user for the model year and stores it in the provided `year` variable
    void promptForModelYear(CarData::Attribute &attribute, int &year);

    // Prompts the user for the odometer reading and stores it in the provided `odometerReading` variable
    void promptForOdometerReading(CarData::Attribute &attribute, int &odometerReading);

    // Displays the validation result based on whether the odometer reading is within a reasonable range
    void displayValidationResult(bool isOriginalMileage);

    // Prompts the user for the car's make and stores it in the provided `make` variable
    void promptForMake(CarData::Attribute &attribute, std::string &make);

    // Prompts the user for the car's model and stores it in the provided `model` variable
    void promptForModel(CarData::Attribute &attribute, std::string &model);

    // Prompts the user for the car's fuel type and stores it in the provided `fuelType` variable
    void promptForFuelType(CarData::Attribute &attribute, std::string &fuelType);

    // Prompts the user for the car's price and stores it in the provided `price` variable
    void promptForPrice(CarData::Attribute &attribute, double &price);

    // Prompts the user for the car's place of origin and stores it in the provided `placeOfOrigin` variable
    void promptForOrigin(CarData::Attribute &attribute, std::string &placeOfOrigin);

    // Prompts the user for the car's transmission type and stores it in the provided `transmissionType` variable
    void promptForTransmissionType(CarData::Attribute &attribute, std::string &transmissionType);

    // Prompts the user for the car's drivetrain type and stores it in the provided `drivetrainType` variable
    void promptForDrivetrainType(CarData::Attribute &attribute, std::string &drivetrainType);

    // Prompts the user about the car's damage history and stores it in the provided `wasDamaged` variable
    void promptForDamageHistory(CarData::Attribute &attribute, bool &wasDamaged);

    // Prompts the user for the number of previous owners and stores it in the provided `previousOwners` vector
    void promptForOwnerCount(CarData::Attribute &attribute, std::vector<std::string> &previousOwners);
};

/*
This preprocessor directive marks the end of the code that is conditional
upon the macro UI_H being defined.
*/
#endif