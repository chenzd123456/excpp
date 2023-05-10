#ifndef __ANY_H__
#define __ANY_H__

#include <string>
#include <vector>

#include <stdint.h>

/**
 * @class Any
 * @brief A class for storing any type of data.
 */
class Any {
  public:
    enum Type {
        UINT8 = 0,
        UINT16,
        UINT32,
        UINT64,
        INT8,
        INT16,
        INT32,
        INT64,
        FLOAT,
        DOUBLE,
        STRING,
        BUFFER,
        POINTER,
        CHAR = UINT8,
    };

    /**
     * @brief Constructor for Any class, takes a uint8_t value.
     * @param value The value to be stored.
     */
    Any(uint8_t value);

    /**
     * @brief Constructor for Any class, takes a uint16_t value.
     * @param value The value to be stored.
     */
    Any(uint16_t value);

    /**
     * @brief Constructor for Any class, takes a uint32_t value.
     * @param value The value to be stored.
     */
    Any(uint32_t value);

    /**
     * @brief Constructor for Any class, takes a uint64_t value.
     * @param value The value to be stored.
     */
    Any(uint64_t value);

    /**
     * @brief Constructor for Any class, takes a int8_t value.
     * @param value The value to be stored.
     */
    Any(int8_t value);

    /**
     * @brief Constructor for Any class, takes a int16_t value.
     * @param value The value to be stored.
     */
    Any(int16_t value);

    /**
     * @brief Constructor for Any class, takes a int32_t value.
     * @param value The value to be stored.
     */
    Any(int32_t value);

    /**
     * @brief Constructor for Any class, takes a int64_t value.
     * @param value The value to be stored.
     */
    Any(int64_t value);

    /**
     * @brief Constructor for Any class, takes a float value.
     * @param value The value to be stored.
     */
    Any(float value);

    /**
     * @brief Constructor for Any class, takes a double value.
     * @param value The value to be stored.
     */
    Any(double value);

    /**
     * @brief Constructor for Any class, takes a char value.
     * @param value The value to be stored.
     */
    Any(char value);

    /**
     * @brief Constructor for Any class, takes a std::string value.
     * @param value The value to be stored.
     */
    Any(const std::string &value);

    /**
     * @brief Constructor for Any class, takes a std::vector<char> value.
     * @param value The value to be stored.
     */
    Any(const std::vector<char> &value);

    /**
     * @brief Constructor for Any class, takes a void* value.
     * @param value The value to be stored.
     */
    Any(void *value);

    /**
     * @brief Destructor for Any class.
     */
    ~Any();

    /**
     * @brief Get the type of the stored value.
     * @return The type of the stored value.
     */
    Type getType() const;

    /**
     * @brief Get the stored value as a uint8_t.
     * @return The stored value as a uint8_t.
     */
    uint8_t asUInt8() const;

    /**
     * @brief Get the stored value as a uint16_t.
     * @return The stored value as a uint16_t.
     */
    uint16_t asUInt16() const;

    /**
     * @brief Get the stored value as a uint32_t.
     * @return The stored value as a uint32_t.
     */
    uint32_t asUInt32() const;

    /**
     * @brief Get the stored value as a uint64_t.
     * @return The stored value as a uint64_t.
     */
    uint64_t asUInt64() const;

    /**
     * @brief Get the stored value as a int8_t.
     * @return The stored value as a int8_t.
     */
    int8_t asInt8() const;

    /**
     * @brief Get the stored value as a int16_t.
     * @return The stored value as a int16_t.
     */
    int16_t asInt16() const;

    /**
     * @brief Get the stored value as a int32_t.
     * @return The stored value as a int32_t.
     */
    int32_t asInt32() const;

    /**
     * @brief Get the stored value as a int64_t.
     * @return The stored value as a int64_t.
     */
    int64_t asInt64() const;

    /**
     * @brief Get the stored value as a float.
     * @return The stored value as a float.
     */
    float asFloat() const;

    /**
     * @brief Get the stored value as a double.
     * @return The stored value as a double.
     */
    double asDouble() const;

    /**
     * @brief Get the stored value as a char.
     * @return The stored value as a char.
     */
    char asChar() const;

    /**
     * @brief Get the stored value as a std::string.
     * @return The stored value as a std::string.
     */
    std::string asString() const;

    /**
     * @brief Get the stored value as a std::vector<char>.
     * @return The stored value as a std::vector<char>.
     */
    std::vector<char> asBuffer() const;

    /**
     * @brief Get the stored value as a void *.
     * @return The stored value as a void *.
     */
    void *asPointer() const;

  private:
    Type type;
    union {
        uint8_t uint8Value;
        uint16_t uint16Value;
        uint32_t uint32Value;
        uint64_t uint64Value;
        int8_t int8Value;
        int16_t int16Value;
        int32_t int32Value;
        int64_t int64Value;
        float floatValue;
        double doubleValue;
        char charValue;
        std::string *stringValue;
        std::vector<char> *bufferValue;
        void *pointerValue;
    };
};
#endif // __ANY_H__