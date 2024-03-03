#pragma once

#include <map>
#include <string>
#include <vector>

#include "debug.hpp"
#include "const.hpp"


struct Range {

    double minimum;
    double maximum;
    double range;

    Range() {}
    Range(double min, double max) : minimum(min), maximum(max), range(max - min) {}
};



class ValueMap {

public:
    ValueMap();
    ValueMap(double value, double minimum, double maximum, const std::string range_key);

    std::vector<std::string> keys(void) const;

    virtual double get(const std::string range_key);
    virtual void set(const double value, const std::string range_key);

    void add_range(const double minimum, const double maximum, const std::string range_key);

protected:
    double normalized_value;

private:
    std::map<const std::string, const Range> ranges;
};