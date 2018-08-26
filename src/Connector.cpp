/**
* @file Connector.cpp
* @brief Implementation of the Connector class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/

#include "Connector.hpp"

#include <algorithm>

namespace procedured
{


/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/

namespace
{

constexpr int NULL_CONNECTOR = -1;

}


/******************************************************************************
* CONSTRUCTORS / DESTRUCTOR ***************************************************
******************************************************************************/

Connector::Connector() :
    Connector(NULL_CONNECTOR)
{
  // do nothing
}

Connector::Connector(
    int const p_type) :
  m_type(p_type),
  m_recievers()
{
  // do nothing
}

/******************************************************************************
* PUBLIC METHODS **************************************************************
******************************************************************************/

int Connector::type() const
{
  return m_type;
}

bool Connector::is_null() const
{
  return m_type == NULL_CONNECTOR;
}

bool Connector::accepts(
    int const p_type) const
{
  return std::find(m_recievers.begin(), m_recievers.end(), p_type) != \
      m_recievers.end();
}

void Connector::add_reciever(
    int const p_type)
{
  m_recievers.emplace_back(p_type);
}



}
