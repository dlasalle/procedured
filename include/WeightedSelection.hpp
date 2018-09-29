/**
* @file WeightedSelection.hpp
* @brief The WeightedSelection class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-21
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
