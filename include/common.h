// include/common.h
#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <sstream>

enum class DataType {
    INT,
    FLOAT,
    CHAR
};

struct Column {
    std::string name;
    DataType type;
    int size;
    bool isPrimaryKey;

    Column(const std::string& n, DataType t, int s = 0, bool pk = false)
        : name(n), type(t), size(s), isPrimaryKey(pk) {}

    std::string toStringForFile() const {
        std::ostringstream oss;
        oss << name << "," << static_cast<int>(type) << "," << size << "," << (isPrimaryKey ? "1" : "0");
        return oss.str();
    }

    static Column fromStringForFile(const std::string& line) {
        std::istringstream iss(line);
        std::string part;

        std::getline(iss, part, ',');
        std::string name = part;

        std::getline(iss, part, ',');
        DataType type = static_cast<DataType>(std::stoi(part));

        std::getline(iss, part, ',');
        int size = std::stoi(part);

        std::getline(iss, part, ',');
        bool isPrimaryKey = (part == "1");


        return Column(name, type, size, isPrimaryKey);
    }
};

#endif // COMMON_H