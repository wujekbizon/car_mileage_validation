#include "Car.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

struct UserData
{
    std::string_view name;
    std::string_view email;
    std::string_view phone;
    std::string_view address;
};

// Define a User class that encapsulates user information using the UserData struct
class User
{
  private:
    UserData userData;

  public:
    // Default constructor for User class
    User() : userData(){};

    // Explicit constructor initializes a User object with given parameters
    explicit User(const UserData &userData) : userData(userData){};

    // Retrieves the user's name
    std::string_view getName() const;

    // Sets the user's name
    void setName(const std::string_view name);

    // Retrieves the user's email address
    std::string_view getEmail() const;

    // Sets the user's email address
    void setEmail(const std::string_view email);

    // Retrieves the user's phone number
    std::string_view getPhone() const;

    // Sets the user's phone number
    void setPhone(const std::string_view phone);

    // Retrieves the user's address
    std::string_view getAddress() const;

    // Sets the user's address
    void setAddress(const std::string_view address);
};

// Implement the Serializable class to define serialization and deserialization methods
class UserDataSerializable : public Serializable
{
  private:
    UserData userData;

  public:
    UserDataSerializable() = default;
    UserDataSerializable(const UserData &userData) : userData(userData){};

    // Converts the UserData object to a JSON string
    const std::string toJSON() const override;

    // Parses a JSON string and populates the UserData object
    void fromJSON(const std::string_view &userDataJSONString) override;

    // Creates a User object from the UserData object
    User createUser() const;
};