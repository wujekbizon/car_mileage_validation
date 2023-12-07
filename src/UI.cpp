#include "./include/UI.h"
#include "./include/Car.h"
#include <iostream>
#include <string>
#include <vector>

void UI::displayWelcomeMessage()
{
    std::cout << "Welcome to the Car Mileage Validation Application" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
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

void UI::gatherCarData(CarData::Attribute &attribute)
{
    switch (attribute.type)
    {
    case CarData::Type::INT: {
        promptForIntAttribute(attribute, *static_cast<int *>(&attribute.value.intVal));
    }
    break;
    case CarData::Type::DOUBLE: {
        promptForDoubleAttribute(attribute, *static_cast<double *>(&attribute.value.doubleVal));
    }
    break;
    case CarData::Type::STRING: {
        promptForStringAttribute(attribute, *static_cast<std::string *>(&attribute.value.stringVal));
    }
    break;
    case CarData::Type::VECTOR: {
        std::vector<std::string> *vecValPtr = &attribute.value.vecVal;
        promptForVectorAttribute(attribute, *vecValPtr);
    }
    break;
    case CarData::Type::BOOL: {
        promptForBoolAttribute(attribute, *static_cast<bool *>(&attribute.value.boolVal));
    }
    break;

    default:
        std::cout << "No type exist!";
        break;
    }
}

void UI::promptForIntAttribute(CarData::Attribute &attribute, int &value) const
{
    std::cout << "Enter the value for " << attribute.name << ": ";
    std::cin >> value;
}
void UI::promptForDoubleAttribute(CarData::Attribute &attribute, double &value) const
{
    std::cout << "Enter the value for " << attribute.name << ": ";
    std::cin >> value;
}

void UI::promptForStringAttribute(CarData::Attribute &attribute, std::string &value) const
{
    std::cout << "Enter the value for " << attribute.name << ": ";
    std::cin >> value;
}

void UI::promptForVectorAttribute(CarData::Attribute &attribute, std::vector<std::string> &value) const
{
    if (attribute.type == CarData::Type::VECTOR)
    {
        std::cout << "Enter the values for " << attribute.name << ": ";

        for (int i = 0; i < attribute.value.vecVal.size(); ++i)
        {
            std::cout << "Value " << i + 1 << ": ";
            std::cin >> attribute.value.vecVal[i];
        }
    }
    else
    {
        std::cout << "Attribute " << attribute.name << " is not of type vector. Skipping prompt.";
    }
}

void UI::promptForBoolAttribute(CarData::Attribute &attribute, bool &value) const
{
    std::cout << "Enter the value for " << attribute.name << " (true/false): ";
    std::string input;
    std::cin >> input;
    while (!(input == "true" || input == "false"))
    {
        std::cout << "Invalid input. Please enter 'true' or 'false': ";
        std::cin >> input;
    }
    value = (input == "true");
}

void UI::promptForVIN(CarData::Attribute &attribute, int &vin)
{
    std::cout << "Enter the car's VIN: ";
    promptForIntAttribute(attribute, vin);
}

void UI::promptForModelYear(CarData::Attribute &attribute, int &year)
{
    std::cout << "Enter the car's model year: ";
    promptForIntAttribute(attribute, year);
}

void UI::promptForOdometerReading(CarData::Attribute &attribute, int &odometerReading)
{
    std::cout << "Enter the car's odometer reading: ";
    promptForIntAttribute(attribute, odometerReading);
}

void UI::promptForMake(CarData::Attribute &attribute, std::string &make)
{
    std::cout << "Please enter the car's make: ";
    promptForStringAttribute(attribute, make);
}

void UI::promptForModel(CarData::Attribute &attribute, std::string &model)
{
    std::cout << "Please enter the car's model: ";
    promptForStringAttribute(attribute, model);
}

void UI::promptForFuelType(CarData::Attribute &attribute, std::string &fuelType)
{
    std::cout << "Please enter the car's fuel type: ";
    promptForStringAttribute(attribute, fuelType);
}

void UI::promptForPrice(CarData::Attribute &attribute, double &price)
{
    std::cout << "Please enter the car's price: ";
    promptForDoubleAttribute(attribute, price);
}

void UI::promptForOrigin(CarData::Attribute &attribute, std::string &placeOfOrigin)
{
    std::cout << "Please enter the car's place of origin: ";
    promptForStringAttribute(attribute, placeOfOrigin);
}

void UI::promptForTransmissionType(CarData::Attribute &attribute, std::string &transmissionType)
{
    std::cout << "Please enter the car's transmission type: ";
    promptForStringAttribute(attribute, transmissionType);
}

void UI::promptForDrivetrainType(CarData::Attribute &attribute, std::string &drivetrainType)
{
    std::cout << "Please enter the car's drivetrain type: ";
    promptForStringAttribute(attribute, drivetrainType);
}

void UI::promptForDamageHistory(CarData::Attribute &attribute, bool &wasDamaged)
{
    std::cout << "Has the car been damaged in any major accidents? (y/n): ";
    promptForBoolAttribute(attribute, wasDamaged);
}

void UI::promptForOwnerCount(CarData::Attribute &attribute, std::vector<std::string> &previousOwners)
{
    std::cout << "Please enter the number of previous owners: ";
    promptForVectorAttribute(attribute, previousOwners);
}
