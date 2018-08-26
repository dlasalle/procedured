/**
* @file Connector.hpp
* @brief The Connector class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/


#ifndef PROCEDURED_CONNECTOR_HPP
#define PROCEDURED_CONNECTOR_HPP

#include <vector>

namespace procedured
{

class Connector
{
  public:
    Connector();

    Connector(
        int p_type);

    int type() const;

    bool is_null() const;

    bool accepts(
        int p_type) const;

    void add_reciever(
        int p_type);

  private:
    int m_type;
    std::vector<int> m_recievers;
};

}

#endif
