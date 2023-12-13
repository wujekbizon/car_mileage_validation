#include "../nlohmann/json.hpp"
#include <iostream>
#include <string_view>
#include <vector>

#ifndef CAR_H
#define CAR_H

struct CarData
{
    enum class Type
    {
        INT,
        DOUBLE,
        STRING,
        VECTOR,
        BOOL
    };

    struct Attribute
    {
        std::string name; // Name of the attribute
        Type type;        // Data type of the attribute
        union Value {
            int intVal;
            double doubleVal;
            std::string stringVal;
            std::vector<std::string> vecVal;
            bool boolVal;
        } value;
    };

    // Maintains a read-only view of the car's vin
    std::string_view vin;
    // Maintains a read-only view of the car's make
    std::string_view make;
    // Maintains a read-only view of the car's model
    std::string_view model;
    // Maintains the car's year
    int year;
    // Maintains the car's odometer reading
    int odometerReading;
    // Maintains a read-only view of the car's fuel type
    std::string_view fuelType;
    // Maintains the car's price
    double price;
    // Maintains a read-only view of the car's place of origin
    std::string_view placeOfOrigin;
    // Maintains a read-only view of the car's transmission type
    std::string_view transmissionType;
    // Maintains a read-only view of the car's drivetrain type
    std::string_view drivetrainType;
    // Indicates whether the car was damaged
    bool wasDamaged;
    // Maintains the count of the car's owners
    int ownerCount;
    // Maintains a vector of the car's previous owners
    std::vector<std::string> previousOwners;
};

/*
  Base class for serializing and deserializing data to and from JSON format.
  This class provides a common interface for serializing and deserializing
  data to and from JSON format. It defines two pure virtual methods, `toJSON()`
  and `fromJSON()`, which must be implemented by derived classes to provide the
  specific logic for converting their respective data types to and from JSON.

  Although it is possible to define default implementations for the `toJSON()`
  and `fromJSON()` methods in this base class, it is generally preferred to
  create such methods directly inside derived classes. This allows for more
  flexibility and control over the serialization and deserialization process,
  and it makes it easier to maintain data-specific logic within the respective
  data classes.
 */
class Serializable
{
    /*
    The = 0 after the method declarations indicates that the methods are pure virtual
    methods. This means that they must be overridden in derived classes, but they
    cannot be directly called from the base class.
    */
  public:
    /**
     * Converts the object's data to a JSON string.
     * @return A JSON representation of the object's data.
     */
    virtual const std::string toJSON() const = 0;

    /**
     * Deserializes JSON data into an object of the appropriate type.
     * @param jsonString The JSON representation of the object.
     */
    virtual void fromJSON(const std::string_view &jsonString) = 0;
};

class Car
{
  private:
    CarData carData;

  public:
    // Default constructor for Car class
    Car() : carData(){};

    /*
    Constructor initializes a Car object with given parameters
    The explicit keyword next to the constructor declaration serves
    to prevent implicit type conversions when initializing a Car object.
    This means that we cannot accidentally initialize a Car object using a different
    type, such as a std::string or double, without explicitly casting.
    */
    explicit Car(const CarData &carData) : carData(carData){};

    // Retrieves the VIN# of the car
    std::string_view getVINNumber() const;

    // Sets the make of the car
    void setVINNumber(std::string_view vin);

    // Retrieves the make of the car
    std::string_view getMake() const;

    // Sets the make of the car
    void setMake(std::string_view make);

    // Retrieves the model of the car
    std::string_view getModel() const;

    // Sets the model of the car
    void setModel(std::string_view model);

    // Retrieves the year of the car
    int getYear() const;

    // Sets the year of the car
    void setYear(int year);

    // Retrieves the odometer reading of the car
    int getOdometerReading() const;

    // Sets the odometer reading of the car
    void setOdometerReading(int odometerReading);

    // Retrieves the fuel type of the car
    std::string_view getFuelType() const;

    // Sets the fuel type of the car
    void setFuelType(const std::string_view fuelType);

    // Retrieves the price of the car
    double getPrice() const;

    // Sets the price of the car
    void setPrice(double price);

    // Retrieves the place of origin of the car
    std::string_view getPlaceOfOrigin() const;

    // Sets the place of origin of the car
    void setPlaceOfOrigin(std::string_view placeOfOrigin);

    // Retrieves the transmission type of the car
    std::string_view getTransmissionType() const;

    // Sets the transmission type of the car
    void setTransmissionType(const std::string_view transmissionType);

    // Retrieves the drivetrain type of the car
    std::string_view getDrivetrainType() const;

    // Sets the drivetrain type of the car
    void setDrivetrainType(const std::string_view drivetrainType);

    // Indicates whether the car was damaged
    bool isWasDamaged() const;

    // Sets whether the car was damaged
    void setWasDamaged(bool wasDamaged);

    // Retrieves the number of owners the car has had
    int getOwnerCount() const;

    // Sets the number of owners the car has had
    void setOwnerCount(int ownerCount);

    // Retrieves the vector of previous owners of the car
    std::vector<std::string> getPreviousOwners() const;

    // Sets the vector of previous owners of the car
    void setPreviousOwners(std::vector<std::string> &previousOwners);
};

class CarDataSerializable : public Serializable
{
  private:
    CarData carData;

  public:
    CarDataSerializable() = default;
    CarDataSerializable(const CarData &carData) : carData(carData)
    {
    }

    // Converts the CarData object to a JSON string
    const std::string toJSON() const override;

    // Parses a JSON string and populates the CarData object
    void fromJSON(const std::string_view &carJSONString) override;

    // Creates a Car object from the CarData object
    Car createCar() const;
};

#endif