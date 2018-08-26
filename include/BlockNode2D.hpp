/**
* @file BlockNode2D.hpp
* @brief The BlockNode2D class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/



#ifndef PROCEDURED_NODE_HPP
#define PROCEDURED_NODE_HPP

#include "Connector.hpp"
#include "Direction.hpp"

#include <vector>
#include <array>

namespace procedured
{

class BlockNode2D
{
  public:
    BlockNode2D(
        int p_id);

    size_t num_connectors() const;

    bool can_connect(
        Direction p_dir,
        int m_type) const;

    bool has_connector(
        Direction p_dir) const;

    Connector const * connector(
        Direction p_dir) const;

    void set_connector(
        Direction p_dir,
        Connector p_conn);

  private:
    int m_id;
    size_t m_num_connectors;
    std::array<Connector, 4> m_connectors;
};

}

#endif
