#include "./include/User.h"

// Converts the internal data of a User object into a JSON-formatted string
const std::string UserDataSerializable::toJSON() const
{
    try
    {
        // Creates a JSON object to hold the car's data using nlohmann library
        nlohmann::json userJSON;
        userJSON["name"] = userData.name;
        userJSON["email"] = userData.email;
        userJSON["phone"] = userData.phone;
        userJSON["address"] = userData.address;

        return userJSON.dump();
    }
    catch (const nlohmann::json::exception &e)
    {
        // Handle issues during JSON serialization
        std::cerr << "Error: Serialization failed: " << e.what() << std::endl;
        return "";
    }
}

// Parses a JSON string to create a Car object
void UserDataSerializable::fromJSON(const std::string_view &userDataJSONString)
{
    try
    {
        UserData userData; // Creates a UserData object to hold the parsed user data
        // Parse the JSON string into a nlohmann::json object

        // Extracts all user data from the JSON object and stores it in the UserData object
        nlohmann::json userJSON = nlohmann::json::parse(userDataJSONString);
        userData.name = userJSON["name"].get<std::string_view>();
        userData.email = userJSON["email"].get<std::string_view>();
        userData.phone = userJSON["phone"].get<std::string_view>();
        userData.address = userJSON["address"].get<std::string_view>();
    }
    catch (const nlohmann::json::exception &e)
    {
        // Handle invalid JSON data
        std::cerr << "Error: Invalid JSON data: " << e.what() << std::endl;
    }
}

User UserDataSerializable::createUser() const
{
    User user(userData);
    return user;
}

// Retrieves the user's name
std::string_view User::getName() const
{
    return userData.name;
}

// Sets the user's name
void User::setName(const std::string_view name)
{
    userData.name = name;
}

// Retrieves the user's email address
std::string_view User::getEmail() const
{
    return userData.email;
}

// Sets the user's email address
void User::setEmail(const std::string_view email)
{
    userData.email = email;
}

// Retrieves the user's phone number
std::string_view User::getPhone() const
{
    return userData.phone;
}

// Sets the user's phone number
void User::setPhone(std::string_view phone)
{
    userData.phone = phone;
}

// Retrieves the user's address
std::string_view User::getAddress() const
{
    return userData.address;
}

// Sets the user's address
void User::setAddress(std::string_view address)
{
    userData.address = address;
}