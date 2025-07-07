// include/value.h
#ifndef VALUE_H
#define VALUE_H

#include "common.h"

class Value {
private:
    DataType type;
    int intVal;
    float floatVal;
    std::string charVal;

public:
    //  (Constructors)
    Value();
    Value(int val);
    Value(float val);
    Value(const std::string& val);
};

#endif // VALUE_H