/**
 * @file IMazeGenerator.h
 * @brief The IMazeGenerator interface.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2018
 * @version 1
 * @date 2018-09-27
 */


#ifndef PROCEDURED_IMAZEGENERATOR_HPP
#define PROCEDURED_IMAZEGENERATOR_HPP


namespace procedured
{


class IMazeGenerator
{
  public:
    virtual Graph generate(
        Graph const * const graph) = 0;

};

}

#endif

