#include "./include/Car.h"

// Constructor for Car class
Car::Car(const std::string_view make, const std::string_view model, int year, long odometerReading,
         const std::string_view fuelType, double price, const std::string_view placeOfOrigin,
         const std::string_view transmissionType, const std::string_view drivetrainType,
         bool wasDamaged, int ownerCount, const std::vector<std::string> &previousOwners)
{
  // Initialize member variables
  this->make = make;
  this->model = model;
  this->year = year;
  this->odometerReading = odometerReading;
  this->fuelType = fuelType;
  this->price = price;
  this->placeOfOrigin = placeOfOrigin;
  this->transmissionType = transmissionType;
  this->drivetrainType = drivetrainType;
  this->wasDamaged = wasDamaged;
  this->ownerCount = ownerCount;
  this->previousOwners = previousOwners;
}
// Get the make of the car
std::string_view Car::getMake() const
{
  return make;
}
// Set the make of the car
void Car::setMake(const std::string_view make)
{
  this->make = make;
}
// Get the model of the car
std::string_view Car::getModel() const
{
  return model;
}
// Set the model of the car
void Car::setModel(const std::string_view model)
{
  this->model = model;
}
// Get the year of the car
int Car::getYear() const
{
  return year;
}
// Set the year of the car
void Car::setYear(int year)
{
  this->year = year;
}
// Get the odometer reading of the car
long Car::getOdometerReading() const
{
  return odometerReading;
}
// Set the odometer reading of the car
void Car::setOdometerReading(long odometerReading)
{
  this->odometerReading = odometerReading;
}
// Get the fuel type of the car
std::string_view Car::getFuelType() const
{
  return fuelType;
}
// Set the fuel type of the car
void Car::setFuelType(const std::string_view fuelType)
{
  this->fuelType = fuelType;
}
// Get the price of the car
double Car::getPrice() const
{
  return price;
}
// Set the price of the car
void Car::setPrice(double price)
{
  this->price = price;
}
// Get the place of origin of the car
std::string_view Car::getPlaceOfOrigin() const
{
  return placeOfOrigin;
}
// Set the place of origin of the car
void Car::setPlaceOfOrigin(const std::string_view placeOfOrigin)
{
  this->placeOfOrigin = placeOfOrigin;
}
// Get the transmission type of the car
std::string_view Car::getTransmissionType() const
{
  return transmissionType;
}
// Set the transmission type of the car
void Car::setTransmissionType(const std::string_view transmissionType)
{
  this->transmissionType = transmissionType;
}
// Get the drivetrain type of the car
std::string_view Car::getDrivetrainType() const
{
  return drivetrainType;
}
// Set the drivetrain type of the car
void Car::setDrivetrainType(const std::string_view drivetrainType)
{
  this->drivetrainType = drivetrainType;
}
// Check if the car was damaged
bool Car::isWasDamaged() const
{
  return wasDamaged;
}
// Set the damaged state of the car
void Car::setWasDamaged(bool wasDamaged)
{
  this->wasDamaged = wasDamaged;
}
// Get the number of previous owners of the car
int Car::getOwnerCount() const
{
  return ownerCount;
}
// Set the number of previous owners of the car
void Car::setOwnerCount(int ownerCount)
{
  this->ownerCount = ownerCount;
}
// Retrieves the vector of previous owners of the car
std::vector<std::string> Car::getPreviousOwners() const
{
  return previousOwners;
}
// Sets the vector of previous owners of the car
void Car::setPreviousOwners(std::vector<std::string> &previousOwners)
{
  this->previousOwners = previousOwners;
}
