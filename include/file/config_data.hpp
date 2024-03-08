#pragma once

#include "file.hpp"


template <class DATATYPE>
class ConfigData : public File<DATATYPE> {

public:
    ConfigData() : File<DATATYPE>() {}
    ConfigData(const std::string path) : File<DATATYPE>(path, false) {
        this->load();
    }


    void read_data(void) {
        std::string name;
        DATATYPE value;

        while (this->file >> name >> value) {
            this->data.insert( {name, value} );
        }
    }


    void write_data(void) {
        for (const std::pair<const std::string, DATATYPE>& pair : this->data) {
            this->file << pair.first << " " << std::to_string(pair.second) << "\n";
        }
    }

};