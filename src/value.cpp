
#include "value.h"


Value::Value() : type(DataType::INT), intVal(0) {}

Value::Value(int val) : type(DataType::INT), intVal(val) {}

Value::Value(float val) : type(DataType::FLOAT), floatVal(val) {}

Value::Value(const std::string& val) : type(DataType::CHAR), charVal(val) {}