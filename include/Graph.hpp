/**
* @file Graph.hpp
* @brief The Graph class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-27
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
  using size_type = std::size_t;

  class Edge
  {
    public:
    Edge(
        size_type const a,
        size_type const b) :
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
        size_type const & rhs) const noexcept
    {
      return m_a < rhs;
    }

    size_type source() const
    {
      return m_a;
    }

    size_type dest() const
    {
      return m_b;
    }

    private:
    size_type m_a;
    size_type m_b;
  };

  Graph(
      size_type num_vertices);

  Graph::size_type num_vertices() const;

  Graph::size_type num_edges() const;

  void add_edge(
      size_type vertex_a,
      size_type vertex_b);

  void remove_edge(
      size_type vertex_a,
      size_type vertex_b);

  bool is_connected(
      size_type vertex_a,
      size_type vertex_b) const;

  std::vector<size_type> get_neighbors(
      size_type vertex) const;


  private:
  size_type m_num_vertices;
  std::set<Edge> m_edges;
};

}


#endif
