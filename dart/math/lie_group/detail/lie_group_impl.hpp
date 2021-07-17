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

#include "dart/math/lie_group/lie_group.hpp"

namespace dart {
namespace math {

//==============================================================================
template <typename Derived>
void LieGroupBase<Derived>::set_identity()
{
  derived().set_identity();
}

//==============================================================================
template <typename Derived>
const typename LieGroupBase<Derived>::LieGroupCoeffs&
LieGroupBase<Derived>::coeffs() const
{
  return derived().coeffs();
}

//==============================================================================
template <typename Derived>
typename LieGroupBase<Derived>::LieGroupCoeffs& LieGroupBase<Derived>::coeffs()
{
  return derived().coeffs();
}

//==============================================================================
template <typename Derived>
const Derived& LieGroupBase<Derived>::derived() const noexcept
{
  return *static_cast<const Derived*>(this);
}

//==============================================================================
template <typename Derived>
Derived& LieGroupBase<Derived>::derived() noexcept
{
  return *static_cast<Derived*>(this);
}

//==============================================================================
template <typename Derived>
typename LieAlgebra<Derived>::LieAlgebraData& LieAlgebra<Derived>::matrix()
{
  return derived().matrix();
}

//==============================================================================
template <typename Derived>
const typename LieAlgebra<Derived>::LieAlgebraData&
LieAlgebra<Derived>::matrix() const
{
  return derived().matrix();
}

//==============================================================================
template <typename Derived>
Derived& LieAlgebra<Derived>::derived() noexcept
{
  return static_cast<Derived>(*this);
}

//==============================================================================
template <typename Derived>
const Derived& LieAlgebra<Derived>::derived() const noexcept
{
  return static_cast<const Derived>(*this);
}

//==============================================================================
template <typename Derived>
typename LieGroupTangent<Derived>::Tangent LieGroupTangent<Derived>::Zero()
{
  return Tangent(TangentData::Zero());
}

//==============================================================================
template <typename Derived>
auto& LieGroupTangent<Derived>::vector()
{
  return derived().vector();
}

//==============================================================================
template <typename Derived>
const auto& LieGroupTangent<Derived>::vector() const
{
  return derived().vector();
}

//==============================================================================
template <typename Derived>
Derived& LieGroupTangent<Derived>::derived() noexcept
{
  return *static_cast<Derived*>(this);
}

//==============================================================================
template <typename Derived>
const Derived& LieGroupTangent<Derived>::derived() const noexcept
{
  return *static_cast<const Derived*>(this);
}

//==============================================================================
template <typename Derived>
typename LieGroupCotangent<Derived>::Cotangent
LieGroupCotangent<Derived>::Zero()
{
  return Cotangent(CotangentData::Zero());
}

//==============================================================================
template <typename Derived>
typename LieGroupCotangent<Derived>::CotangentData&
LieGroupCotangent<Derived>::vector()
{
  return derived().vector();
}

//==============================================================================
template <typename Derived>
const typename LieGroupCotangent<Derived>::CotangentData&
LieGroupCotangent<Derived>::vector() const
{
  return derived().vector();
}

//==============================================================================
template <typename Derived>
Derived& LieGroupCotangent<Derived>::derived() noexcept
{
  return *static_cast<Derived*>(this);
}

//==============================================================================
template <typename Derived>
const Derived& LieGroupCotangent<Derived>::derived() const noexcept
{
  return *static_cast<const Derived*>(this);
}

} // namespace math
} // namespace dart
