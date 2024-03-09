#include "food.hpp"


Food::Food(const Celltype cell_type) : cell_type(cell_type) {}


void Food::repos(Grid& grid) const {
    std::vector<Cell*> empty_cells = grid.empty_cells();
    
    unsigned int random_index = GetRandomValue(UINT_ZERO, empty_cells.size() - UINT_ONE);
    empty_cells[random_index]->set_state(cell_type, BONUS_ALIVE_CYCLES);
}


Apple::Apple() : Food(APPLE) {}


Bonus::Bonus() : Food(BONUS) {}
