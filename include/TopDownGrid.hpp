/**
* @file TopDownGrid.hpp
* @brief The TopDownGrid class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-10-09
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


#ifndef PROCEDURED_TOPDOWNGRID_HPP
#define PROCEDURED_TOPDOWNGRID_HPP

#include <cstddef>
#include <vector>

namespace procedured
{

class TopDownGrid
{
  public:
    enum cell_type {
      PASSAGE,
      DOORWAY,
      ROOM,
      NONE
    };

    using size_type = std::size_t;

    /**
    * @brief Create a new topdown grid.
    *
    * @param width The width of the grid (X).
    * @param height The height of the grid (Y).
    */
    TopDownGrid(
        size_type width,
        size_type height);

    /**
    * @brief Get the total number of cells in the grid.
    *
    * @return The number of cells.
    */
    size_type num_cells() const;

    /**
    * @brief Set the given cell in the grid to the specified cell type.
    *
    * @param x The cell's x position.
    * @param y The cell's y position.
    * @param cell The cell type to set.
    */
    void set_cell(
        size_type x,
        size_type y,
        cell_type cell);

    /**
    * @brief Get the type of cell at the given location.
    *
    * @param x The cell's x position.
    * @param y The cell's y position.
    *
    * @return The cell type.
    */
    cell_type cell_at(
        size_type x,
        size_type y) const;

  private:
    size_type m_width;
    size_type m_height;
    std::vector<cell_type> m_cells;

    /**
    * @brief Get the index in the m_cells array of a given cell.
    *
    * @param x The cell's x position.
    * @param y The cell's y position.
    *
    * @return The 1D index.
    */
    size_type index_of(
        size_type x,
        size_type y) const;
};

}

#endif



