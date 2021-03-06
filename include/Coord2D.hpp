/**
* @file Coord2D.hpp
* @brief The Coord2D class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
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



#ifndef PROCEDURED_COORD2D_HPP
#define PROCEDURED_COORD2D_HPP


namespace procedured
{

class Coord2D
{
  public:
    Coord2D(
        int const x,
        int const y) :
      m_x(x),
      m_y(y)
    {
      // do nothing
    }

    int x()
    {
      return m_x;
    }

    int y()
    {
      return m_y;
    }

    operator<(
        Coord2D const & other) const
    {
      return m_u < other.m_y || (m_y == other.m_y && m_x < other.m_x);
    }
};

}

#endif
