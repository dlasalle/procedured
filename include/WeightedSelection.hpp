/**
* @file WeightedSelection.hpp
* @brief The WeightedSelection class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-21
*/

#ifndef PROCEDURED_WEIGHTEDSELECTION_HPP
#define PROCEDURED_WEIGHTEDSELECTION_HPP

#include <cassert>
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>
#include <random>

namespace procedured
{

template <typename T>
class WeightedSelection
{
  public:
    /**
    * @brief Create a WeightedSelection object.
    *
    * @param p_items The set of items in the weighted selection.
    */
    WeightedSelection(
        std::vector<std::pair<double, T>> p_items) :
      m_items(p_items),
      m_prefix(1, 0)
    {
      // build total weight 
      double total_weight = 0.0;
      for (size_t i = 0; i < m_items.size(); ++i) {
        total_weight += m_items[i].first;
        m_prefix.emplace_back(total_weight);
      }
    }

    /**
    * @brief Make a pseudo random selection. Given then same input parameters,
    * this method will always return the same item.
    *
    * @param p_id The id value.
    * @param p_seed The seed value.
    *
    * @return The selected item. 
    */
    T select(
        unsigned int p_id,
        unsigned int p_seed) const
    {
      // generate a number between 0.0 and m_prefix.back() from id and seed
      // TODO: This is temperatory means of generating a fraction, we'll need
      // to switch to a simpler+faster solution down the road.
      std::mt19937 gen(p_id^p_seed);
      unsigned int const rn = gen();

      double const frac = m_prefix.back() * (static_cast<double>(rn) / \
          static_cast<double>(gen.max() - gen.min()));

      size_t const idx = \
          std::upper_bound(m_prefix.begin(), m_prefix.end(), frac) - \
          m_prefix.begin()-1;
      assert(idx < m_items.size());

      return m_items[idx].second;
    }

    
  private:
    std::vector<std::pair<double, T>> m_items;
    std::vector<double> m_prefix;
};

}

#endif
