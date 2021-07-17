/*
 * Copyright (c) 2011-2021, The DART development contributors
 * All rights reserved.
 *
 * The list of contributors can be found at:
 *   https://github.com/dartsim/dart/blob/main/LICENSE
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <limits>
#include <type_traits>

#include "dart/common/stl_utility.hpp"

namespace dart {
namespace math {

template <typename Scalar = double>
static constexpr Scalar eps()
{
  if constexpr (std::is_same_v<Scalar, float>) {
    return 1e-6;
  } else if constexpr (std::is_same_v<Scalar, double>) {
    return 1e-12;
  } else if constexpr (std::is_same_v<Scalar, long double>) {
    return 1e-18;
  } else {
    common::static_assert_no_match();
    return {};
  }
}

template <typename Scalar = double>
static constexpr Scalar pi()
{
  return static_cast<Scalar>(
      3.141592653589793238462643383279502884197169399375105820974944592L);
}

template <typename Scalar = double>
static constexpr Scalar two_pi()
{
  return 2.0 * pi<Scalar>();
}

template <typename Scalar = double>
static constexpr Scalar half_pi()
{
  return 0.5 * pi<Scalar>();
}

template <typename Scalar = double>
static constexpr Scalar pi_sqr()
{
  return pi<Scalar>() * pi<Scalar>();
}

template <typename Scalar = double>
static constexpr Scalar phi()
{
  return static_cast<Scalar>(
      1.618033988749894848204586834365638117720309179805762862135448623L);
}

template <typename Scalar = double>
static constexpr Scalar inf()
{
  return std::numeric_limits<Scalar>::infinity();
}

} // namespace math
} // namespace dart
