#include "container/Any.h"

Any::~Any() {
    if (type == STRING) {
        delete stringValue;
    } else if (type == BUFFER) {
        delete bufferValue;
    }
}

Any::Type Any::getType() const { return type; }

uint8_t Any::asUInt8() const { return uint8Value; }

uint16_t Any::asUInt16() const { return uint16Value; }

uint32_t Any::asUInt32() const { return uint32Value; }

uint64_t Any::asUInt64() const { return uint64Value; }

int8_t Any::asInt8() const { return int8Value; }

int16_t Any::asInt16() const { return int16Value; }

int32_t Any::asInt32() const { return int32Value; }

int64_t Any::asInt64() const { return int64Value; }

float Any::asFloat() const { return floatValue; }

double Any::asDouble() const { return doubleValue; }

char Any::asChar() const { return charValue; }

std::string Any::asString() const { return *stringValue; }

std::vector<char> Any::asBuffer() const { return *bufferValue; }

void *Any::asPointer() const { return pointerValue; }

Any::Any(uint8_t value) : type(UINT8), uint8Value(value) {}

Any::Any(uint16_t value) : type(UINT16), uint16Value(value) {}

Any::Any(uint32_t value) : type(UINT32), uint32Value(value) {}

Any::Any(uint64_t value) : type(UINT64), uint64Value(value) {}

Any::Any(int8_t value) : type(INT8), int8Value(value) {}

Any::Any(int16_t value) : type(INT16), int16Value(value) {}

Any::Any(int32_t value) : type(INT32), int32Value(value) {}

Any::Any(int64_t value) : type(INT64), int64Value(value) {}

Any::Any(float value) : type(FLOAT), floatValue(value) {}

Any::Any(double value) : type(DOUBLE), doubleValue(value) {}

Any::Any(char value) : type(CHAR), charValue(value) {}

Any::Any(const std::string &value)
    : type(STRING), stringValue(new std::string(value)) {}

Any::Any(const std::vector<char> &value)
    : type(BUFFER), bufferValue(new std::vector<char>(value)) {}

Any::Any(void *value) : type(POINTER), pointerValue(value) {}