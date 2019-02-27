/**
 * page.h
 *
 * Wrapper around actual data page in main memory and also contains bookkeeping
 * information used by buffer pool manager like pin_count/dirty_flag/page_id.
 * Use page as a basic unit within the database system
 */

#pragma once

#include <cstring>

#include "common/config.h"

namespace cmudb {

class Page {
  friend class BufferPoolManager;

public:
  Page() { ResetMemory(); }

  ~Page(){};

  inline char *GetData() { return data_; } // get actual data page content

private:
  // method used by buffer pool manager
  inline void ResetMemory() { memset(data_, 0, PAGE_SIZE); }

  // members
  char data_[PAGE_SIZE]; // actual data
  page_id_t page_id_ = INVALID_PAGE_ID;
  int pin_count_ = 0;
  bool is_dirty_ = false;
};

} // namespace cmudb
