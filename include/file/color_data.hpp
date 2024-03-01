#pragma once


#include "file.hpp"
#include "raylib.hpp"


class ColorData : public File<Color> {

public:
    ColorData();
    ColorData(const std::string path);

protected:

    void read_data(void);
    void write_data(void);

};