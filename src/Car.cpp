#include "./include/Car.h"

// Converts the internal data of a Car object into a JSON-formatted string
const std::string CarDataSerializable::toJSON() const
{
    try
    {
        // Creates a JSON object to hold the car's data using nlohmann library
        nlohmann::json carJSON;
        // Add data from the CarData object to the JSON object
        carJSON["vin"] = carData.vin;
        carJSON["make"] = carData.make;
        carJSON["model"] = carData.model;
        carJSON["year"] = carData.year;
        carJSON["odometerReading"] = carData.odometerReading;
        carJSON["fuelType"] = carData.fuelType;
        carJSON["price"] = carData.price;
        carJSON["placeOfOrigin"] = carData.placeOfOrigin;
        carJSON["transmissionType"] = carData.transmissionType;
        carJSON["drivetrainType"] = carData.drivetrainType;
        carJSON["wasDamaged"] = carData.wasDamaged;
        carJSON["ownerCount"] = carData.ownerCount;
        carJSON["previousOwners"] = carData.previousOwners;

        // Converts the JSON object to a string and returns it
        return carJSON.dump();
    }
    catch (const nlohmann::json::exception &e)
    {
        // Handle issues during JSON serialization
        std::cerr << "Error: Serialization failed: " << e.what() << std::endl;
        return "";
    }
}

// Parses a JSON string to create a Car object
void CarDataSerializable::fromJSON(const std::string_view &carJSONString)
{
    try
    {
        CarData carData; // Creates a CarData object to hold the parsed car data
        // Parse the JSON string into a nlohmann::json object
        nlohmann::json carJSON = nlohmann::json::parse(carJSONString);

        // Extracts all car data from the JSON object and stores it in the CarData object
        carData.vin = carJSON["vin"].get<std::string_view>();
        carData.make = carJSON["make"].get<std::string_view>();
        carData.model = carJSON["model"].get<std::string_view>();
        carData.year = carJSON["year"].get<int>();
        carData.odometerReading = carJSON["odometerReading"].get<int>();
        carData.fuelType = carJSON["fuelType"].get<std::string_view>();
        carData.price = carJSON["price"].get<double>();
        carData.placeOfOrigin = carJSON["placeOfOrigin"].get<std::string_view>();
        carData.transmissionType = carJSON["transmissionType"].get<std::string_view>();
        carData.drivetrainType = carJSON["drivetrainType"].get<std::string_view>();
        carData.wasDamaged = carJSON["wasDamaged"].get<bool>();
        carData.ownerCount = carJSON["ownerCount"].get<int>();
        carData.previousOwners = carJSON["previousOwners"].get<std::vector<std::string>>();
    }
    catch (const nlohmann::json::exception &e)
    {
        // Handle invalid JSON data
        std::cerr << "Error: Invalid JSON data: " << e.what() << std::endl;
    }
}

Car CarDataSerializable::createCar() const
{
    Car car(carData);
    return car;
}

// Get the VIN# of the car
std::string_view Car::getVINNumber() const
{
    return carData.vin;
}
// Set the VIN# of the car
void Car::setVINNumber(const std::string_view vin)
{
    carData.vin = vin;
}
// Get the make of the car
std::string_view Car::getMake() const
{
    return carData.make;
}
// Set the make of the car
void Car::setMake(const std::string_view make)
{
    carData.make = make;
}
// Get the model of the car
std::string_view Car::getModel() const
{
    return carData.model;
}
// Set the model of the car
void Car::setModel(const std::string_view model)
{
    carData.model = model;
}
// Get the year of the car
int Car::getYear() const
{
    return carData.year;
}
// Set the year of the car
void Car::setYear(int year)
{
    carData.year = year;
}
// Get the odometer reading of the car
int Car::getOdometerReading() const
{
    return carData.odometerReading;
}
// Set the odometer reading of the car
void Car::setOdometerReading(int odometerReading)
{
    carData.odometerReading = odometerReading;
}
// Get the fuel type of the car
std::string_view Car::getFuelType() const
{
    return carData.fuelType;
}
// Set the fuel type of the car
void Car::setFuelType(const std::string_view fuelType)
{
    carData.fuelType = fuelType;
}
// Get the price of the car
double Car::getPrice() const
{
    return carData.price;
}
// Set the price of the car
void Car::setPrice(double price)
{
    carData.price = price;
}
// Get the place of origin of the car
std::string_view Car::getPlaceOfOrigin() const
{
    return carData.placeOfOrigin;
}
// Set the place of origin of the car
void Car::setPlaceOfOrigin(const std::string_view placeOfOrigin)
{
    carData.placeOfOrigin = placeOfOrigin;
}
// Get the transmission type of the car
std::string_view Car::getTransmissionType() const
{
    return carData.transmissionType;
}
// Set the transmission type of the car
void Car::setTransmissionType(const std::string_view transmissionType)
{
    carData.transmissionType = transmissionType;
}
// Get the drivetrain type of the car
std::string_view Car::getDrivetrainType() const
{
    return carData.drivetrainType;
}
// Set the drivetrain type of the car
void Car::setDrivetrainType(const std::string_view drivetrainType)
{
    carData.drivetrainType = drivetrainType;
}
// Check if the car was damaged
bool Car::isWasDamaged() const
{
    return carData.wasDamaged;
}
// Set the damaged state of the car
void Car::setWasDamaged(bool wasDamaged)
{
    carData.wasDamaged = wasDamaged;
}
// Get the number of previous owners of the car
int Car::getOwnerCount() const
{
    return carData.ownerCount;
}
// Set the number of previous owners of the car
void Car::setOwnerCount(int ownerCount)
{
    carData.ownerCount = ownerCount;
}
// Retrieves the vector of previous owners of the car
std::vector<std::string> Car::getPreviousOwners() const
{
    return carData.previousOwners;
}
// Sets the vector of previous owners of the car
void Car::setPreviousOwners(std::vector<std::string> &previousOwners)
{
    carData.previousOwners = previousOwners;
}
