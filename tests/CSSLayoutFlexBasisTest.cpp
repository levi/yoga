/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include <CSSLayout/CSSLayout-internal.h>
#include <CSSLayoutTestUtils/CSSLayoutTestUtils.h>
#include <gtest/gtest.h>

TEST(CSSLayoutTest, flex_basis) {
  CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionRow);
  CSSNodeStyleSetWidth(root, 300);
  CSSNodeStyleSetHeight(root, 100);

  CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child0, 1);
  CSSNodeStyleSetFlexBasis(root_child0, 100);
  CSSNodeStyleSetWidth(root_child0, 200);
  CSSNodeStyleSetHeight(root_child0, 100);
  CSSNodeInsertChild(root, root_child0, 0);

  CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child1, 1);
  CSSNodeStyleSetWidth(root_child1, 100);
  CSSNodeStyleSetHeight(root_child1, 100);
  CSSNodeInsertChild(root, root_child1, 1);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(300, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(200, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root_child1));
}