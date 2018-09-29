/**
* @file DepthFirstMazeGenerator.hpp
* @brief The DepthFirstMazeGenerator class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-27
*/


#ifndef PROCEDURED_DEPTHFIRSTMAZEGENERATOR_HPP
#define PROCEDURED_DEPTHFIRSTMAZEGENERATOR_HPP

#include "IMazeGenerator.hpp"

#include <cstdint>
#include <random>

namespace procedured
{

class DepthFirstMazeGenerator : public IMazeGenerator
{
  public:
    DepthFirstMazeGenerator(
        uint32_t seed);

    Graph generate(
        Graph const * const graph) override;

  private:
    std::mt19937 m_rng;
};



}


#endif

