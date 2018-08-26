/**
* @file WeightedSelectionBuilder.hpp
* @brief The WeightedSelectionBuilder class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-21
*/



#ifndef PROCEDURED_WEIGHTEDSELECTIONBUILDER_HPP
#define PROCEDURED_WEIGHTEDSELECTIONBUILDER_HPP

namespace procedured
{

template <typename T>
class WeightedSelectionBuilder
{
  public:
  void add_item(
      double const p_weight,
      T const p_item)
  {
    m_items.emplace_back(p_weight, p_item);
  }

  WeightedSelection<T> build() const
  {
    return WeightedSelection(m_items);
  }

  private:
  std::vector<std::pair<double, T>> m_items;
};

}

#endif
