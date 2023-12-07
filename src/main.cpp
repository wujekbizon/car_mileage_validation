#include "./include/Car.h"
#include "./include/UI.h"
#include "./nlohmann/json.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

using json = nlohmann::json;

int main()
{
    UI ui;
    // ui.displayWelcomeMessage();

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

    Car car = Car(carData);

    std::string carJSONString =
        "[{\"vin\":\"1GNEK13ZX3R298984\",\"make\":\"Toyota\",\"model\":\"Corolla\",\"year\":2023,\"odometerReading\":"
        "100000,\"fuelType\":"
        "\"Gasoline\",\"price\":20000.00,\"placeOfOrigin\":\"Japan\",\"transmissionType\":\"Automatic\","
        "\"drivetrainType\":\"Front-wheel drive\",\"wasDamaged\":false,\"ownerCount\":1,\"previousOwners\":[\"John "
        "Doe\",\"Jane Doe\"]}]";

    json carJSON = car.toJSON();
    std::cout << std::setw(4) << carJSON << std::endl;
    std::stringstream input;
    input << carJSONString;
    std::string line;
    while (std::getline(input, line))
    {
        // std::cout << line;
        std::cout << std::setw(4) << json::parse(line);
    }

    // json car1JSON = json::parse(carJSON);
    // std::cout << std::setw(4) << car1JSON << std::endl;
    return 0;
}