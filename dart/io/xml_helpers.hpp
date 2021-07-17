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

#include <string>

#include <tinyxml2.h>

#include "dart/common/console.hpp"
#include "dart/common/eigen_include.hpp"
#include "dart/common/resource_retriever.hpp"
#include "dart/io/export.hpp"
#include "dart/math/MathTypes.hpp"
#include "dart/math/type.hpp"

namespace dart {
namespace io {

template <typename Scalar, int N>
std::string to_string(const math::Vector<Scalar, N>& v);

template <typename Scalar>
std::string to_string(
    const math::Isometry3<Scalar>& v,
    const std::string& rotation_type = "intrinsic");

template <typename Scalar, int N>
math::Vector<Scalar, N> to_vector(const std::string& str);

DART_IO_API math::Vector2d to_vector2d(const std::string& str);
DART_IO_API math::Vector3d to_vector3d(const std::string& str);
DART_IO_API math::Vector4d to_vector4d(const std::string& str);
DART_IO_API math::Vector6d to_vector6d(const std::string& str);

DART_IO_API math::Vector2i to_vector2i(const std::string& str);
DART_IO_API math::Vector3i to_vector3i(const std::string& str);

template <typename Scalar>
math::VectorX<Scalar> to_vector_x(const std::string& str);

/// Converts string to isometry3
///
/// \param[in] str: String to convert. The expected format is an array of 6
/// numbers distinguished by space. The first three numbers are for position,
/// and the last three numbers are for orientation.
/// \param[in] rotation_type: (optional) How to convert 3-D vector to a rotation
/// matrix. Supported types are {intrinsic, extrinsic} where the default is
/// intrinsic.
template <typename Scalar>
math::Isometry3<Scalar> to_isometry3(
    const std::string& str, const std::string& rotation_type = "intrinsic");
// TODO(JS): Change to return the success

DART_IO_API std::string getValueString(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API bool getValueBool(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API int getValueInt(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API unsigned int getValueUInt(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API float getValueFloat(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API double getValueDouble(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::Vector2d getValueVector2d(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::Vector3d getValueVector3d(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::Vector3i getValueVector3i(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::Vector6d getValueVector6d(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::VectorXd getValueVectorXd(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::Isometry3d getValueIsometry3d(
    const tinyxml2::XMLElement* parentElement, const std::string& name);
DART_IO_API Eigen::Isometry3d getValueIsometry3dWithExtrinsicRotation(
    const tinyxml2::XMLElement* parentElement, const std::string& name);

// TODO(JS): Deprecate
DART_IO_API void openXMLFile(
    tinyxml2::XMLDocument& doc,
    const common::Uri& uri,
    const common::ResourceRetrieverPtr& retriever = nullptr);

DART_IO_API bool readXmlFile(
    tinyxml2::XMLDocument& doc,
    const common::Uri& uri,
    const common::ResourceRetrieverPtr& retrieverOrNullPtr = nullptr);

DART_IO_API bool hasElement(
    const tinyxml2::XMLElement* parentElement, const std::string& name);

DART_IO_API const tinyxml2::XMLElement* getElement(
    const tinyxml2::XMLElement* parentElement, const std::string& name);

DART_IO_API tinyxml2::XMLElement* getElement(
    tinyxml2::XMLElement* parentElement, const std::string& name);

DART_IO_API bool hasAttribute(
    const tinyxml2::XMLElement* element, const char* const name);

DART_IO_API std::string getAttributeString(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API bool getAttributeBool(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API int getAttributeInt(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API unsigned int getAttributeUInt(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API float getAttributeFloat(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API double getAttributeDouble(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API char getAttributeChar(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API Eigen::Vector2i getAttributeVector2i(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API Eigen::Vector2d getAttributeVector2d(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API Eigen::Vector3d getAttributeVector3d(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API Eigen::Vector4d getAttributeVector4d(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API Eigen::Vector6d getAttributeVector6d(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
DART_IO_API Eigen::VectorXd getAttributeVectorXd(
    const tinyxml2::XMLElement* element, const std::string& attributeName);
template <std::size_t N>
Eigen::Matrix<double, N, 1> getAttributeVectorNd(
    const tinyxml2::XMLElement* element, const std::string& attributeName)
{
  const std::string val = getAttributeString(element, attributeName);
  return to_vector<double, N>(val);
}

/// TemplatedElementEnumerator is a convenience class to help visiting all the
/// child elements of given parent element. This class is templated to cover
/// const and non-const tinyxml2::XMLElement types.
template <typename ElementType>
class TemplatedElementEnumerator
{
protected:
  using ElementPtr = ElementType*;
  using ElementRef = ElementType&;

public:
  /// Constructor that takes parent element and
  TemplatedElementEnumerator(
      ElementPtr parentElement, const std::string& childElementName)
    : mParentElement(parentElement),
      mChildElementName(childElementName),
      mCurrentElement(nullptr)
  {
  }

  /// Destructor
  ~TemplatedElementEnumerator() {}

  /// Set the current element to the next sibling element or to the first child
  /// element of given parent element if it exists; returns success
  bool next()
  {
    if (!mParentElement)
      return false;

    if (mCurrentElement) {
      mCurrentElement
          = mCurrentElement->NextSiblingElement(mChildElementName.c_str());
    } else {
      mCurrentElement
          = mParentElement->FirstChildElement(mChildElementName.c_str());
    }

    if (!valid())
      mParentElement = nullptr;

    return valid();
  }

  /// Get the current element
  ElementPtr get() const
  {
    return mCurrentElement;
  }

  /// Dereference operator
  ElementPtr operator->() const
  {
    return mCurrentElement;
  }

  /// Dereference operator
  ElementRef operator*() const
  {
    return *mCurrentElement;
  }

  /// Equality operator
  bool operator==(const TemplatedElementEnumerator<ElementType>& rhs) const
  {
    // If they point at the same node, then the names must match
    return (this->mParentElement == rhs.mParentElement)
           && (this->mCurrentElement == rhs.mCurrentElement)
           && (this->mCurrentElement != nullptr
               || (this->mChildElementName == rhs.mChildElementName));
  }

  /// Assignment operator
  TemplatedElementEnumerator<ElementType>& operator=(
      const TemplatedElementEnumerator<ElementType>& rhs)
  {
    this->mParentElement = rhs.mParentElement;
    this->mChildElementName = rhs.mChildElementName;
    this->mCurrentElement = rhs.mCurrentElement;

    return *this;
  }

private:
  /// Returns true if the current element is valid (not a nullptr)
  bool valid() const
  {
    return mCurrentElement != nullptr;
  }

private:
  /// Parent element
  ElementPtr mParentElement;

  /// Child element name
  std::string mChildElementName;

  /// Currently visiting child element
  ElementPtr mCurrentElement;
};

// ElementEnumerator is for iterating elements for
using ElementEnumerator = TemplatedElementEnumerator<tinyxml2::XMLElement>;
using ConstElementEnumerator
    = TemplatedElementEnumerator<const tinyxml2::XMLElement>;

DART_IO_API bool copyNode(
    tinyxml2::XMLNode* destParent, const tinyxml2::XMLNode& src);

DART_IO_API bool copyChildNodes(
    tinyxml2::XMLNode* destParent, const tinyxml2::XMLNode& src);

} // namespace io
} // namespace dart

#include "dart/io/detail/xml_helpers_impl.hpp"
