#include <cstdio>
#include <cstdlib>

#include "buffer/buffer_pool_manager.h"
#include "page/header_page.h"
#include "gtest/gtest.h"

namespace cmudb {

TEST(HeaderPageTest, UnitTest) {
  BufferPoolManager *buffer_pool_manager = new BufferPoolManager(20, "test.db");
  HeaderPage *page =
      static_cast<HeaderPage *>(buffer_pool_manager->FetchPage(0));
  ASSERT_NE(nullptr, page);
  page->Init();

  for (int i = 1; i < 28; i++) {
    std::string name = std::to_string(i);
    EXPECT_EQ(page->InsertRecord(name, i), true);
  }

  for (int i = 27; i >= 1; i--) {
    std::string name = std::to_string(i);
    page_id_t root_id;
    EXPECT_EQ(page->GetRootId(name, root_id), true);
    // std::cout << "root page id is " << root_id << '\n';
  }

  for (int i = 1; i < 28; i++) {
    std::string name = std::to_string(i);
    EXPECT_EQ(page->UpdateRecord(name, i + 10), true);
  }

  for (int i = 27; i >= 1; i--) {
    std::string name = std::to_string(i);
    page_id_t root_id;
    EXPECT_EQ(page->GetRootId(name, root_id), true);
    // std::cout << "root page id is " << root_id << '\n';
  }

  for (int i = 1; i < 28; i++) {
    std::string name = std::to_string(i);
    EXPECT_EQ(page->DeleteRecord(name), true);
  }

  EXPECT_EQ(page->GetRecordCount(), 0);

  delete buffer_pool_manager;
}
} // namespace cmudb
