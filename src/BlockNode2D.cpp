/**
* @file BlockNode2D.cpp
* @brief The BlockNode2D class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/


#include "BlockNode2D.hpp"

namespace procedured
{


/******************************************************************************
* HELPER FUNCTIONS ************************************************************
******************************************************************************/

namespace
{

template<typename T, size_t N>
T& fetch(
    std::array<T,N>& a,
    Direction const dir)
{
  size_t const dir_idx = static_cast<size_t>(dir);
  assert(dir_idx < a.size());
  return a[dir_idx];
}

}

/******************************************************************************
* CONSTRUCTORS / DESTRUCTOR ***************************************************
******************************************************************************/

BlockNode2D::BlockNode2D(
    int const p_id) :
  m_id(p_id),
  m_num_connectors(0),
  m_connectors{}
{
  // do nothing
}

/******************************************************************************
* PUBLIC METHODS **************************************************************
******************************************************************************/

size_t BlockNode2D::num_connectors() const
{
  return m_num_connectors;
}

bool BlockNode2D::can_connect(
    Direction const p_dir,
    int const m_type) const
{
  return has_connector(p_dir) &&
         connector(p_dir)->accepts(m_type);
}

bool BlockNode2D::has_connector(
    Direction const p_dir) const
{
  return connector(p_dir)->is_null();
}

Connector const * BlockNode2D::connector(
    Direction const p_dir) const
{
  return &m_connectors[static_cast<size_t>(p_dir)];
}

void BlockNode2D::set_connector(
    Direction const p_dir,
    Connector const p_conn)
{
  int delta = 0;

  if (connector(p_dir)->is_null()) {
    delta += 1;
  }
  if (p_conn.is_null()) {
    delta -= 1;
  }

  m_num_connectors += delta;

  m_connectors[static_cast<size_t>(p_dir)] = p_conn;
}

}
