#include <iostream>

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
    virtual std::string toJSON() const = 0;

    /**
     * Deserializes JSON data into an object of the appropriate type.
     * @param jsonString The JSON representation of the object.
     */
    virtual void fromJSON(const std::string_view &jsonString) = 0;
};