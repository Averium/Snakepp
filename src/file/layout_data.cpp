#include "layout_data.hpp"



LayoutData::LayoutData() : File() {}


LayoutData::LayoutData(const std::string path) : File(path, true) {
    load();
}


void LayoutData::read_data(void) {
    std::string name;
    int x;
    int y;

    while (file >> name >> x >> y) {
        data[name] =Vector(x, y);
    }
}


void LayoutData::write_data(void) {
    for (std::pair<const std::string, Vector>& pair : data) {
        file << pair.first << " " << pair.second.x << " " << pair.second.y << "\n";
    }
}