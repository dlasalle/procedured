/**
* @file Graph.hpp
* @brief The Graph class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-27
*/



#ifndef PROCEDURED_GRAPH_HPP
#define PROCEDURED_GRAPH_HPP

#include <cstddef>
#include <vector>
#include <set>

namespace procedured
{


class Graph
{
  public:
  using vertex_type = std::size_t;

  class Edge
  {
    public:
    Edge(
        vertex_type const a,
        vertex_type const b) :
      m_a(a),
      m_b(b)
    {
      // do nothing
    }

    bool operator==(
        Edge const & rhs) const noexcept
    {
      return m_a == rhs.m_a && m_b == rhs.m_b;
    }

    bool operator<(
        Edge const & rhs) const noexcept
    {
      return m_a < rhs.m_a || (m_a == rhs.m_a && m_b < rhs.m_b);
    }

    bool operator<(
        vertex_type const & rhs) const noexcept
    {
      return m_a < rhs;
    }

    vertex_type source() const
    {
      return m_a;
    }

    vertex_type dest() const
    {
      return m_b;
    }

    private:
    vertex_type m_a;
    vertex_type m_b;
  };

  Graph(
      vertex_type num_vertices);

  void add_edge(
      vertex_type vertex_a,
      vertex_type vertex_b);

  void remove_edge(
      vertex_type vertex_a,
      vertex_type vertex_b);

  bool is_connected(
      vertex_type vertex_a,
      vertex_type vertex_b) const;

  std::vector<vertex_type> get_neighbors(
      vertex_type vertex) const;


  private:
  vertex_type m_num_vertices;
  std::set<Edge> m_edges;
};

}


#endif
