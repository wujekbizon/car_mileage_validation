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
    void displayWelcomeMessage();
    void gatherCarData(CarData::Attribute &attribute);

  public:
    void promptForVIN(CarData::Attribute &attribute, int &vin);
    void promptForIntAttribute(CarData::Attribute &attribute, int &value) const;
    void promptForDoubleAttribute(CarData::Attribute &attribute, double &value) const;
    void promptForStringAttribute(CarData::Attribute &attribute, std::string &value) const;
    void promptForVectorAttribute(CarData::Attribute &attribute, std::vector<std::string> &value) const;
    void promptForBoolAttribute(CarData::Attribute &attribute, bool &value) const;
    void promptForModelYear(CarData::Attribute &attribute, int &year);
    void promptForOdometerReading(CarData::Attribute &attribute, int &odometerReading);
    void displayValidationResult(bool isOriginalMileage);
    void promptForMake(CarData::Attribute &attribute, std::string &make);
    void promptForModel(CarData::Attribute &attribute, std::string &model);
    void promptForFuelType(CarData::Attribute &attribute, std::string &fuelType);
    void promptForPrice(CarData::Attribute &attribute, double &price);
    void promptForOrigin(CarData::Attribute &attribute, std::string &placeOfOrigin);
    void promptForTransmissionType(CarData::Attribute &attribute, std::string &transmissionType);
    void promptForDrivetrainType(CarData::Attribute &attribute, std::string &drivetrainType);
    void promptForDamageHistory(CarData::Attribute &attribute, bool &wasDamaged);
    void promptForOwnerCount(CarData::Attribute &attribute, std::vector<std::string> &previousOwners);
    void promptForPreviousOwners();
    bool validateOdometerReading();
    void displayCollectedData();
};

/*
This preprocessor directive marks the end of the code that is conditional
upon the macro UI_H being defined.
*/
#endif