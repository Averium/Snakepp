#pragma once

#include "file.hpp"
#include "integer_vector.hpp"


class LayoutData : public File<Vector> {

public:
    LayoutData();
    LayoutData(const std::string path);

protected:

    void read_data(void);
    void write_data(void);

};