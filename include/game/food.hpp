#pragma once

#include <vector>

#include "const.hpp"
#include "grid.hpp"


class Food {

public:
    Food(const Celltype cell_type);

    virtual void repos(Grid& grid) const;

protected:
    const Celltype cell_type;
};


class Bonus : public Food {
    public: Bonus();
};


class Apple : public Food {
    public: Apple();
};