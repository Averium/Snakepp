#include "value_map.hpp"


ValueMap::ValueMap() : normalized_value(0.0F) {
    add_range(FLOAT_ZERO, FLOAT_ONE, "NORMALIZED");
}


ValueMap::ValueMap(double value, double minimum, double maximum, const std::string range_key) {
    add_range(FLOAT_ZERO, FLOAT_ONE, "NORMALIZED");
    add_range(minimum, maximum, range_key);
    this->set(value, range_key);
}


std::vector<std::string> ValueMap::keys(void) const {
    std::vector<std::string> keys_vector;
    keys_vector.reserve(ranges.size());

    for (const auto& pair : this->ranges) {
        keys_vector.push_back(pair.first);
    }

    return keys_vector;
}


double ValueMap::get(const std::string range_key) {
    const Range range = this->ranges[range_key];
    return this->normalized_value * range.range + range.minimum;
}


void ValueMap::set(const double value, const std::string range_key) {
    const Range range = this->ranges[range_key];
    this->normalized_value = (value - range.minimum) / range.range;
}


void ValueMap::add_range(const double minimum, const double maximum, const std::string range_key) {
    const Range range = Range(minimum, maximum);
    this->ranges.insert(std::make_pair(range_key, range));
}