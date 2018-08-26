/**
* @file Grid2D.hpp
* @brief The Grid2D class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/



#ifndef PROCEDURED_GRID2D_HPP
#define PROCEDURED_GRID2D_HPP

#include "Coord2D.hpp"
#include "BlockNode2D.hpp"

namespace procedured
{

class Grid2D
{
  public:
    void add_block(
        Coord2D coord,
        BlockNode2D block);
  
  private:
    std::map<Coord2D, BlockNode2D> m_blocks;
};

}

#endif
