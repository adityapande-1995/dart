/*
 * Copyright (c) 2011-2022, The DART development contributors
 * All rights reserved.
 *
 * The list of contributors can be found at:
 *   https://github.com/dartsim/dart/blob/master/LICENSE
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

#ifndef DART_COMMON_OBJECTPOOL_HPP_
#define DART_COMMON_OBJECTPOOL_HPP_

#include <array>
#include <mutex>

#include "dart/common/MemoryAllocator.hpp"
#include "dart/common/MemoryAllocatorDebugger.hpp"

namespace dart::common {

/// Memory allocator optimized for allocating many objects of the same or
/// similar sizes
template <typename T>
class ObjectPool
{
public:
  using Debug = MemoryAllocatorDebugger<ObjectPool>;

  /// Constructor
  ///
  /// \param[in] baseAllocator: (optional) Base memory allocator.
  /// \param[in] initialAllocation: (optional) Bytes to initially allocate.
  explicit ObjectPool(
      MemoryAllocator& baseAllocator = MemoryAllocator::GetDefault());

  /// Destructor
  ~ObjectPool();

  /// Returns the base allocator
  [[nodiscard]] const MemoryAllocator& getBaseAllocator() const;

  /// Returns the base allocator
  [[nodiscard]] MemoryAllocator& getBaseAllocator();

  template <typename... Args>
  [[nodiscard]] T* construct(Args&&... args) noexcept;

  // Documentation inherited
  void print(std::ostream& os = std::cout, int indent = 0) const;

private:
  // Documentation inherited
  [[nodiscard]] void* allocate() noexcept;

  // Documentation inherited
  void deallocate(void* pointer);

  struct MemoryUnit
  {
    /// Pointer to next memory block
    MemoryUnit* mNext;
  };

  struct MemoryBlock
  {
    /// Pointer to the first memory unit
    MemoryUnit* mMemoryUnits;

    size_t mSize;
  };

  /// The base allocator to allocate memory chunk
  MemoryAllocator& mBaseAllocator;

  /// Mutex for for mNumAllocatedMemoryBlocks, mNumMemoryBlocks,
  /// mFreeMemoryUnits, and mAllocatedMemoryBlocks.
  mutable std::mutex mMutex;

  /// The array of memory blocks.
  ///
  /// This array is a placeholder of allocated memory blocks. Initially this
  /// contains nullptr as the elements.
  MemoryBlock* mMemoryBlocks;

  /// The size of mMemoryBlocks.
  ///
  /// This is simply the current size of mMemoryBlocks. The value doesn't mean
  /// the actual count of the allocated memory blocks.
  int mMemoryBlocksSize;

  /// The count of the allocated memory blocks in use.
  int mNumAllocatedMemoryBlocks;

  MemoryUnit* mFreeMemoryUnit;
};

} // namespace dart::common

#include "dart/common/detail/ObjectPool-impl.hpp"

#endif // DART_COMMON_OBJECTPOOL_HPP_
