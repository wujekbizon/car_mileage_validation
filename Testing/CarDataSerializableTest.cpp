#include "../src/include/Car.h"
#include <gtest/gtest.h>

using json = nlohmann::json;

TEST(CarDataSerializableTest, ToJSON)
{
    CarData carData;
    carData.vin = "123456";
    carData.make = "Toyota";
    carData.model = "Corolla";
    carData.year = 2023;
    carData.odometerReading = 12345;
    carData.fuelType = "Gasoline";
    carData.price = 25000;
    carData.placeOfOrigin = "Japan";
    carData.transmissionType = "Automatic";
    carData.drivetrainType = "FWD";
    carData.wasDamaged = false;
    carData.ownerCount = 1;

    CarDataSerializable carDataSerializable(carData);

    std::string jsonString = carDataSerializable.toJSON();

    // Verify the generated JSON string
    json carJSON = json::parse(jsonString);

    EXPECT_EQ(carJSON["vin"], carData.vin);
    EXPECT_EQ(carJSON["make"], carData.make);
    EXPECT_EQ(carJSON["model"], carData.model);
    EXPECT_EQ(carJSON["year"], carData.year);
    EXPECT_EQ(carJSON["odometerReading"], carData.odometerReading);
    EXPECT_EQ(carJSON["fuelType"], carData.fuelType);
    EXPECT_EQ(carJSON["price"], carData.price);
    EXPECT_EQ(carJSON["placeOfOrigin"], carData.placeOfOrigin);
    EXPECT_EQ(carJSON["transmissionType"], carData.transmissionType);
    EXPECT_EQ(carJSON["drivetrainType"], carData.drivetrainType);
    EXPECT_EQ(carJSON["wasDamaged"], carData.wasDamaged);
    EXPECT_EQ(carJSON["ownerCount"], carData.ownerCount);
}