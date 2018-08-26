/**
* @file Coord2D.hpp
* @brief The Coord2D class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
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
