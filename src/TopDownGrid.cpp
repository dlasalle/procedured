/**
* @file TopDownGrid.cpp
* @brief Implementation of the TopDownGrid class.
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

#include "TopDownGrid.hpp"

namespace procedured
{

/******************************************************************************
* CONSTRUCTORS / DESTRUCTOR ***************************************************
******************************************************************************/

TopDownGrid::TopDownGrid(
    size_type const width,
    size_type const height) :
  m_width(width),
  m_height(height),
  m_cells(width*height, NONE)
{
  // do nothing
}

/******************************************************************************
* PUBLIC METHODS **************************************************************
******************************************************************************/

TopDownGrid::size_type TopDownGrid::num_cells() const
{
  return m_cells.size();
}

void TopDownGrid::set_cell(
    size_type const x,
    size_type const y,
    cell_type const cell)
{
  m_cells[index_of(x,y)] = cell;
}

TopDownGrid::cell_type TopDownGrid::cell_at(
    size_type const x,
    size_type const y) const
{
  return m_cells[index_of(x,y)];
}


/******************************************************************************
* PRIVATE METHODS *************************************************************
******************************************************************************/

TopDownGrid::size_type TopDownGrid::index_of(
    size_type const x,
    size_type const y) const
{
  return y*m_width + x;
}


}
