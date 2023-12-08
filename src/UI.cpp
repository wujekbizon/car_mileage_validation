#include "./include/UI.h"
#include "./include/Car.h"
#include <iostream>
#include <string>
#include <vector>

void UI::displayWelcomeMessage()
{
    std::cout << "\n\n";

    std::cout << "____________________________________________________________________________________________________"
              << std::endl;
    std::cout << "Welcome to the Comprehensive Car Inspection Assistant!" << std::endl;
    std::cout << "____________________________________________________________________________________________________"
              << std::endl;
    std::cout << "\n\n";

    std::cout << "We're delighted to assist you in assessing the condition of your car and making informed decisions "
                 "about its maintenance and potential resale value."
              << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "To get started, please gather the following information about your car:" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "1. VIN (Vehicle Identification Number): This unique identifier is essential for accessing detailed "
                 "vehicle history and specifications."
              << std::endl;
    std::cout << "2. Year, make, and model: Knowing these details allows us to accurately match your car's "
                 "specifications to our database."
              << std::endl;
    std::cout << "3. Odometer reading: This is crucial for evaluating the car's mileage and potential wear and tear."
              << std::endl;
    std::cout << "4. Previous owner information (if available): If you know who the previous owners were, please "
                 "provide their names and contact details for further investigation."
              << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "Armed with this information, we'll guide you through a series of questions and validation checks to "
                 "assess the overall condition of your car. The results will provide insights into potential issues, "
                 "maintenance needs, and the car's market value."
              << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "Prepare yourself for a comprehensive inspection of your car's:**" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout
        << "1. Exterior: We'll evaluate the paint condition, bodywork, dents, scratches, and signs of damage or rust."
        << std::endl;
    std::cout << "2. Interior: We'll inspect the seats, upholstery, dashboard, controls, and overall cleanliness and "
                 "functionality."
              << std::endl;
    std::cout << "3. Engine compartment: We'll check for fluid leaks, visible damage, and overall cleanliness to "
                 "assess the engine's condition."
              << std::endl;
    std::cout << "4. Drivetrain: We'll evaluate the transmission, differential, and driveshaft for any signs of wear, "
                 "noise, or vibration."
              << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "Remember, the more accurate and complete the information you provide, the more comprehensive and "
                 "valuable our assessment will be."
              << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "Are you ready to begin the inspection? (y/n)" << std::endl;
}

void UI::displayValidationResult(bool isOriginalMileage)
{
    /*
    Provide a summary of all the validation checks performed and their respective results.
    This would give the user a comprehensive overview of the car's overall condition.
    Incorporate color-coding or other visual cues to enhance the presentation of the feedback.
    This could help the user quickly identify areas of concern and prioritize further investigation.
    Generate a detailed report that can be saved or exported for future reference.
    This would be particularly useful for professional car inspectors or buyers who need to document their findings.
    Integrate with external tools or services for more in-depth analysis and recommendations.
    This could involve connecting to databases of historical car data, VIN lookup services, or vehicle history reports.
    */
    if (isOriginalMileage)
    {
        std::cout << "The car's mileage is likely original." << std::endl;
    }
    else
    {
        std::cout << "The car's mileage may be tampered with." << std::endl;
    }
}

// Gathers car data from the user
void UI::gatherCarData(CarData::Attribute &attribute)
{
    // Determines the data type and calls the corresponding prompt function
    switch (attribute.type)
    {
        // Prompts the user for an integer value
    case CarData::Type::INT: {
        promptForIntAttribute(attribute, *static_cast<int *>(&attribute.value.intVal));
    }
    break;
    // Prompts the user for a floating-point value
    case CarData::Type::DOUBLE: {
        promptForDoubleAttribute(attribute, *static_cast<double *>(&attribute.value.doubleVal));
    }
    break;
    // Prompts the user for a string value
    case CarData::Type::STRING: {
        promptForStringAttribute(attribute, *static_cast<std::string *>(&attribute.value.stringVal));
    }
    break;
    // Prompts the user for a vector of strings
    case CarData::Type::VECTOR: {
        promptForVectorAttribute(attribute, *static_cast<std::vector<std::string> *>(&attribute.value.vecVal));
    }
    break;
    // Prompts the user for a boolean value
    case CarData::Type::BOOL: {
        promptForBoolAttribute(attribute, *static_cast<bool *>(&attribute.value.boolVal));
    }
    break;

    default:
        // Handles unknown data types
        std::cout << "No type exist!";
        break;
    }
}

// Prompts the user for an integer value for the specified CarData::Attribute
void UI::promptForIntAttribute(CarData::Attribute &attribute, int &value) const
{
    // Displays a prompt to the user requesting the value for the specified attribute
    std::cout << "Enter the value for " << attribute.name << ": ";
    // Retrieves the input from the user and stores it in the `value` variable
    std::cin >> value;
}

// Prompts the user for a double-precision floating-point value for the specified CarData::Attribute
void UI::promptForDoubleAttribute(CarData::Attribute &attribute, double &value) const
{
    // Displays a prompt to the user requesting the value for the specified attribute
    std::cout << "Enter the value for " << attribute.name << ": ";
    // Retrieves the input from the user and stores it in the `value` variable
    std::cin >> value;
}

// Prompts the user for a string value for the specified CarData::Attribute
void UI::promptForStringAttribute(CarData::Attribute &attribute, std::string &value) const
{
    // Displays a prompt to the user requesting the value for the specified attribute
    std::cout << "Enter the value for " << attribute.name << ": ";
    // Retrieves the input from the user and stores it in the `value` variable
    std::cin >> value;
}

// Prompts the user for a vector of string values for the specified CarData::Attribute
void UI::promptForVectorAttribute(CarData::Attribute &attribute, std::vector<std::string> &value) const
{
    // Checks if the attribute type is vector
    if (attribute.type == CarData::Type::VECTOR)
    {
        // Displays a prompt to the user requesting the value for the specified attribute
        std::cout << "Enter the values for " << attribute.name << ": ";
        // Iterates through the vector's elements
        for (int i = 0; i < attribute.value.vecVal.size(); ++i)
        {
            // Prompts the user for value at index `i`
            std::cout << "Value " << i + 1 << ": ";
            // Reads the input from the user and stores it in the `value` vector
            std::cin >> attribute.value.vecVal[i];
        }
    }
    else // If the attribute type is not vector
    {
        // Informs the user and skips the prompt
        std::cout << "Attribute " << attribute.name << " is not of type vector. Skipping prompt.";
    }
}

// Prompts the user for a boolean value for the specified CarData::Attribute
void UI::promptForBoolAttribute(CarData::Attribute &attribute, bool &value) const
{
    // Displays a prompt to the user requesting the value for the specified attribute
    std::cout << "Enter the value for " << attribute.name << " (true/false): ";

    // Reads the user input into a string variable
    std::string input;
    std::cin >> input;

    // Validates the input to ensure it is either "true" or "false"
    while (!(input == "true" || input == "false"))
    {
        // Informs the user of the invalid input and requests a new input
        std::cout << "Invalid input. Please enter 'true' or 'false': ";
        std::cin >> input;
    }
    // Assigns the value of the input to the output variable
    value = (input == "true"); // Converts the string to a boolean value
}

// Prompts the user for the VIN (Vehicle Identification Number) for the specified CarData::Attribute
void UI::promptForVIN(CarData::Attribute &attribute, std::string &vin)
{
    // Displays a prompt to the user requesting the VIN
    std::cout << "Enter the car's VIN: ";
    // Delegates the task of prompting for an integer value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, vin);
}

// Prompts the user for the car's model year
void UI::promptForModelYear(CarData::Attribute &attribute, int &year)
{
    // Displays a prompt requesting the car's model year
    std::cout << "Enter the car's model year: ";
    // Delegate the task of prompting for an integer value to the `promptForIntAttribute()` function, ensuring that the
    // input is validated as an integer
    promptForIntAttribute(attribute, year);
}

// Prompts the user for the car's odometer reading
void UI::promptForOdometerReading(CarData::Attribute &attribute, int &odometerReading)
{
    // Displays a prompt requesting the car's odometer reading
    std::cout << "Enter the car's odometer reading: ";
    // Delegates the task of prompting for an integer value to the `promptForIntAttribute()` function, ensuring that the
    // input is validated as an integer
    promptForIntAttribute(attribute, odometerReading);
}

// Prompts the user for the car's make
void UI::promptForMake(CarData::Attribute &attribute, std::string &make)
{
    // Displays a prompt to the user requesting the make
    std::cout << "Please enter the car's make: ";

    // Delegates the task of prompting for a string value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, make);
}

// Prompts the user for the car's model
void UI::promptForModel(CarData::Attribute &attribute, std::string &model)
{
    // Displays a prompt to the user requesting the model
    std::cout << "Please enter the car's model: ";

    // Delegates the task of prompting for a string value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, model);
}

// Prompts the user for the car's fuel type
void UI::promptForFuelType(CarData::Attribute &attribute, std::string &fuelType)
{
    // Displays a prompt to the user requesting the fuel type
    std::cout << "Please enter the car's fuel type: ";
    // Delegates the task of prompting for a string value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, fuelType);
}

// Prompts the user for the car's price
void UI::promptForPrice(CarData::Attribute &attribute, double &price)
{
    // Displays a prompt to the user requesting the price
    std::cout << "Please enter the car's price: ";
    // Delegates the task of prompting for a double-precision floating-point value to the `promptForDoubleAttribute()`
    // function, ensuring that the input is validated as a double-precision floating-point number
    promptForDoubleAttribute(attribute, price);
}

// Prompts the user for the car's place of origin
void UI::promptForOrigin(CarData::Attribute &attribute, std::string &placeOfOrigin)
{
    // Displays a prompt to the user requesting the origin
    std::cout << "Please enter the car's place of origin: ";
    // Delegates the task of prompting for a string value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, placeOfOrigin);
}

// Prompts the user for the car's transmission type
void UI::promptForTransmissionType(CarData::Attribute &attribute, std::string &transmissionType)
{
    // Displays a prompt to the user requesting the transmission type
    std::cout << "Please enter the car's transmission type: ";
    // Delegates the task of prompting for a string value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, transmissionType);
}

// Prompts the user for the car's drivetrain type
void UI::promptForDrivetrainType(CarData::Attribute &attribute, std::string &drivetrainType)
{
    // Displays a prompt to the user requesting the drivetrain type
    std::cout << "Please enter the car's drivetrain type: ";
    // Delegates the task of prompting for a string value to the `promptForStringAttribute()` function, ensuring that
    // the input is validated as a string
    promptForStringAttribute(attribute, drivetrainType);
}

// Prompts the user about the car's damage history
void UI::promptForDamageHistory(CarData::Attribute &attribute, bool &wasDamaged)
{
    // Displays a prompt to the user confirming any major damage history
    std::cout << "Has the car been damaged in any major accidents? (y/n): ";
    // Delegates the task of prompting for a boolean value to the `promptForBoolAttribute()` function, ensuring that
    // the input is validated as a valid boolean value ('y' or 'n')
    promptForBoolAttribute(attribute, wasDamaged);
}

// Prompts the user for the number of previous owners
void UI::promptForOwnerCount(CarData::Attribute &attribute, std::vector<std::string> &previousOwners)
{
    // Prompt the user if there are any previous owners
    std::cout << "Do you know the names of the previous car owners? (y/n): ";

    char response;
    std::cin >> response;

    if (response == 'y' || response == 'Y')
    {
        // Delegates the task of prompting for a vector of strings to the `promptForVectorAttribute()` function,
        // ensuring that the input is validated as a vector of strings of the specified size
        promptForVectorAttribute(attribute, previousOwners);
    }
}
