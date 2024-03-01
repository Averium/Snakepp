#pragma once


#include "file.hpp"


template <class DATATYPE>
class DataFile : public File<DATATYPE> {

public:
    DataFile() : File<DATATYPE>() {}
    DataFile(const std::string path) : File<DATATYPE>(path, false) {}


    void read_data(void) {
        std::string name;
        DATATYPE value;

        while (this->file >> name >> value) {
            this->data[name] = value;
        }
    }


    void write_data(void) {
        for (const std::pair<const std::string, DATATYPE>& pair : this->data) {
            this->file << pair.first << " " << std::to_string(pair.second) << "\n";
        }
    }

};