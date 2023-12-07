#include "./include/Car.h"

const std::string Car::toJSON() const
{
    nlohmann::json carJSON;
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

    return carJSON.dump();
}

// static Car Car::fromJSON(const std::string_view &carJSONString)
// {
//     nlohmann::json carJSON = nlohmann::json::parse(carJSONString);

//     CarData carData;
//     carData.make = carJSON["make"];
//     carData.model = carJSON["model"];
//     carData.year = carJSON["year"];
//     carData.odometerReading = carJSON["odometerReading"];
//     carData.fuelType = carJSON["fuelType"];
//     carData.price = carJSON["price"];
//     carData.placeOfOrigin = carJSON["placeOfOrigin"];
//     carData.transmissionType = carJSON["transmissionType"];
//     carData.drivetrainType = carJSON["drivetrainType"];
//     carData.wasDamaged = carJSON["wasDamaged"];
//     carData.ownerCount = carJSON["ownerCount"];

//     std::vector<std::string> previousOwners;
//     for (auto &previousOwner : carJSON["previousOwners"])
//     {
//         previousOwners.push_back(previousOwner);
//     }
//     carData.previousOwners = previousOwners;

//     return Car(carData);
// }

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
long Car::getOdometerReading() const
{
    return carData.odometerReading;
}
// Set the odometer reading of the car
void Car::setOdometerReading(long odometerReading)
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
