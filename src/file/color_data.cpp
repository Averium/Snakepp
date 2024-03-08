#include "color_data.hpp"
#include "const.hpp"


ColorData::ColorData() : File() {}


ColorData::ColorData(const std::string path) : File(path, true) {
    load();
}


void ColorData::read_data(void) {
    std::string name;
    unsigned int r, g, b;

    while (file >> name >> r >> g >> b) {
        data[name] = {(unsigned char)(r), (unsigned char)(g), (unsigned char)(b), 255U};
    }
}


void ColorData::write_data(void) {
    for (const auto& pair : data) {
        Color color = pair.second;
        file << pair.first << " " << color.r << " " << color.g << " " << color.b << "\n";
    }
}