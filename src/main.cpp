#include "./include/Car.h"
#include "./include/UI.h"
#include <iomanip>
#include <iostream>

int main()
{
    UI ui;
    ui.displayWelcomeMessage();

    /*
    For example, in this VIN “1GNEK13ZX3R298984,” the “G” indicates a vehicle manufactured by
    General Motors. The first three characters, which includes the country identifier digit is
    part of the World Manufacturer Identifier (WMI).
    */

    CarData carData;
    carData.vin = "1GNEK13ZX3R298984";
    carData.make = "Toyota";
    carData.model = "Corolla";
    carData.year = 2003;
    carData.odometerReading = 100000;
    carData.fuelType = "Gasoline";
    carData.price = 20000.00;
    carData.placeOfOrigin = "Japan";
    carData.transmissionType = "Automatic";
    carData.drivetrainType = "Front-wheel drive";
    carData.wasDamaged = false;
    carData.ownerCount = 1;
    carData.previousOwners = std::vector<std::string>{"John Doe", "Jane Doe"};

    CarDataSerializable carDataSerializable(carData);
    std::string carJSON = carDataSerializable.toJSON();

    std::cout << carJSON << std::endl;

    // Access and use the Car object
    carDataSerializable.fromJSON(carJSON);

    Car car = carDataSerializable.createCar();
    std::cout << car.getMake() << car.getVINNumber() << std::endl;

    return 0;
}