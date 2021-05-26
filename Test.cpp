/**
 * AUTHOR: liel berniker
 * 
 */

#include "doctest.h"
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

const unsigned int ZERO = 0, ONE = 1, TWO = 2, THEREE = 3, FOUR = 4, FIVE = 5;
const unsigned int SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10;
const double ONE_4 = 1.4, EIGHT_66 = 8.66, TWEN_3488 = 20.3488;
const string HELLO = "hello", MOM = "mom", DAD = "dad", SHALOM = "shalom", LOVE = "love";
const unsigned int HOUNDRED = 100, FOUR_EIGHT = 48;

TEST_CASE("add root method tests")
{

  BinaryTree<int> tree_of_ints;
  CHECK_NOTHROW(tree_of_ints.add_root(ONE));
  auto it1 = tree_of_ints.begin_preorder();
  if (it1 != nullptr)
  {
    CHECK(*it1 == ONE);
    CHECK(*it1 != TEN);
  }
  CHECK_NOTHROW(tree_of_ints.add_root(FIVE));
  auto it2 = tree_of_ints.begin_preorder();
  if (it2 != nullptr)
  {
    CHECK(*it2 == FIVE);
    CHECK_FALSE(*it2 == ONE);
  }

  BinaryTree<string> tree_of_strings;
  CHECK_NOTHROW(tree_of_strings.add_root(MOM));
  auto it3 = tree_of_strings.begin_inorder();
  if (it3 != nullptr)
  {
    CHECK(*it3 == MOM);
    CHECK_FALSE(*it3 == DAD);
  }
  CHECK_NOTHROW(tree_of_strings.add_root(LOVE));
  auto it4 = tree_of_strings.begin_inorder();
  if (it4 != nullptr)
  {
    CHECK(*it4 == LOVE);
    CHECK_FALSE(*it4 == MOM);
  }

  BinaryTree<double> tree_of_doub;
  CHECK_NOTHROW(tree_of_doub.add_root(ONE_4));
  auto it5 = tree_of_doub.begin_inorder();
  if (it5 != nullptr)
  {
    CHECK(*it5 == ONE_4);
    CHECK_FALSE(*it5 == EIGHT_66);
  }
  CHECK_NOTHROW(tree_of_doub.add_root(TWEN_3488));
  auto it6 = tree_of_doub.begin_inorder();
  if (it6 != nullptr)
  {
    CHECK(*it6 == TWEN_3488);
    CHECK_FALSE(*it6 == ONE_4);
  }
}

TEST_CASE("add left method tests")
{

  BinaryTree<int> tree_of_ints;
  CHECK_THROWS(tree_of_ints.add_left(ONE, EIGHT));
  tree_of_ints.add_root(ONE);
  CHECK_NOTHROW(tree_of_ints.add_left(ONE, EIGHT));
  auto it1 = tree_of_ints.begin_inorder();
  if (it1 != nullptr)
  {
    CHECK(*it1 == EIGHT);
    CHECK_FALSE(*it1 == ONE);
  }
  CHECK_THROWS(tree_of_ints.add_left(FIVE, EIGHT));
  CHECK_NOTHROW(tree_of_ints.add_left(EIGHT, TWO));
  auto it2 = tree_of_ints.begin_inorder();
  if (it2 != nullptr)
  {
    CHECK(*it2 == TWO);
    CHECK_FALSE(*it2 == EIGHT);
  }

  BinaryTree<string> tree_of_strings;
  CHECK_THROWS(tree_of_strings.add_left(MOM, DAD));
  tree_of_strings.add_root(DAD);
  CHECK_NOTHROW(tree_of_strings.add_left(DAD, LOVE));
  auto it3 = tree_of_strings.begin_inorder();
  if (it3 != nullptr)
  {
    CHECK(*it3 == LOVE);
    CHECK_FALSE(*it3 == DAD);
  }
  CHECK_THROWS(tree_of_strings.add_left(MOM, SHALOM));
  CHECK_NOTHROW(tree_of_strings.add_left(LOVE, SHALOM));
  auto it4 = tree_of_strings.begin_inorder();
  if (it4 != nullptr)
  {
    CHECK(*it4 == SHALOM);
    CHECK_FALSE(*it4 == LOVE);
  }

  BinaryTree<double> tree_of_doub;
  CHECK_THROWS(tree_of_doub.add_left(TWEN_3488, EIGHT_66));
  tree_of_doub.add_root(EIGHT_66);
  CHECK_NOTHROW(tree_of_doub.add_left(EIGHT_66, TWEN_3488));
  auto it5 = tree_of_doub.begin_inorder();
  if (it5 != nullptr)
  {
    CHECK(*it5 == TWEN_3488);
    CHECK_FALSE(*it5 == EIGHT_66);
  }
  CHECK_THROWS(tree_of_doub.add_left(ONE_4, EIGHT_66));
  CHECK_NOTHROW(tree_of_doub.add_left(TWEN_3488, ONE_4));
  auto it6 = tree_of_doub.begin_inorder();
  if (it6 != nullptr)
  {
    CHECK(*it6 == ONE_4);
    CHECK_FALSE(*it6 == EIGHT_66);
  }
}

TEST_CASE("add right method tests")
{

  BinaryTree<int> tree_of_ints;
  CHECK_THROWS(tree_of_ints.add_right(ONE, EIGHT));
  tree_of_ints.add_root(ONE);
  CHECK_NOTHROW(tree_of_ints.add_right(ONE, EIGHT));
  auto it1 = tree_of_ints.begin_postorder();
  if (it1 != nullptr)
  {
    CHECK(*it1 == EIGHT);
    CHECK_FALSE(*it1 == ONE);
  }
  CHECK_THROWS(tree_of_ints.add_right(FIVE, EIGHT));
  CHECK_NOTHROW(tree_of_ints.add_right(EIGHT, TWO));
  auto it2 = tree_of_ints.begin_postorder();
  if (it2 != nullptr)
  {
    CHECK(*it2 == TWO);
    CHECK_FALSE(*it2 == EIGHT);
  }

  BinaryTree<string> tree_of_strings;
  CHECK_THROWS(tree_of_strings.add_right(MOM, DAD));
  tree_of_strings.add_root(DAD);
  CHECK_NOTHROW(tree_of_strings.add_right(DAD, LOVE));
  auto it3 = tree_of_strings.begin_postorder();
  if (it3 != nullptr)
  {
    CHECK(*it3 == LOVE);
    CHECK_FALSE(*it3 == DAD);
  }
  CHECK_THROWS(tree_of_strings.add_right(MOM, SHALOM));
  CHECK_NOTHROW(tree_of_strings.add_right(LOVE, SHALOM));
  auto it4 = tree_of_strings.begin_postorder();
  if (it4 != nullptr)
  {
    CHECK(*it4 == SHALOM);
    CHECK_FALSE(*it4 == LOVE);
  }
  BinaryTree<double> tree_of_doub;
  CHECK_THROWS(tree_of_doub.add_right(TWEN_3488, EIGHT_66));
  tree_of_doub.add_root(EIGHT_66);
  CHECK_NOTHROW(tree_of_doub.add_right(EIGHT_66, TWEN_3488));
  auto it5 = tree_of_doub.begin_postorder();
  if (it5 != nullptr)
  {
    CHECK(*it5 == TWEN_3488);
    CHECK_FALSE(*it5 == EIGHT_66);
  }
  CHECK_THROWS(tree_of_doub.add_right(ONE_4, EIGHT_66));
  CHECK_NOTHROW(tree_of_doub.add_right(TWEN_3488, ONE_4));
  auto it6 = tree_of_doub.begin_postorder();
  if (it6 != nullptr)
  {
    CHECK(*it6 == ONE_4);
    CHECK_FALSE(*it6 == EIGHT_66);
  }
}
TEST_CASE("begin preorder method tests")
{

  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(ONE);
  CHECK_NOTHROW(tree_of_ints.add_left(ONE, EIGHT));
  CHECK_NOTHROW(tree_of_ints.add_right(ONE, TWO));
  auto it2 = tree_of_ints.begin_preorder();
  if (it2 != nullptr)
  {
    CHECK(*it2 == ONE);
    CHECK_FALSE(*it2 == TWO);
    ++it2;
    CHECK(*it2 == EIGHT);
    ++it2;
    CHECK(*it2 == TWO);
  }

  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root(LOVE);
  CHECK_NOTHROW(tree_of_strings.add_left(LOVE, MOM));
  CHECK_NOTHROW(tree_of_strings.add_right(LOVE, DAD));
  auto it3 = tree_of_strings.begin_preorder();
  if (it3 != nullptr)
    {
      CHECK(*it3 == LOVE);
      CHECK_FALSE(*it3 == MOM);
      ++it3;
      CHECK(*it3 == MOM);
      ++it3;
      CHECK(*it3 == DAD);
    }

  BinaryTree<double> tree_of_doub;
  tree_of_doub.add_root(ONE_4);
  CHECK_NOTHROW(tree_of_doub.add_left(ONE_4, EIGHT_66));
  CHECK_NOTHROW(tree_of_doub.add_right(ONE_4, TWEN_3488));
  auto it4 = tree_of_doub.begin_preorder();
  if (it4 != nullptr)
  {
    CHECK(*it4 == ONE_4);
    CHECK_FALSE(*it4 == EIGHT_66);
    ++it4;
    CHECK(*it4 == EIGHT_66);
    ++it4;
    CHECK(*it4 == TWEN_3488);
  }
}
TEST_CASE("begin inorder method tests")
{

  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(ONE);
  CHECK_NOTHROW(tree_of_ints.add_left(ONE, EIGHT));
  CHECK_NOTHROW(tree_of_ints.add_right(ONE, TWO));
  auto it2 = tree_of_ints.begin_inorder();
  if (it2 != nullptr)
  {
    CHECK(*it2 == EIGHT);
    CHECK_FALSE(*it2 == TWO);
    ++it2;
    CHECK(*it2 == ONE);
    ++it2;
    CHECK(*it2 == TWO);
  }

  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root(LOVE);
  CHECK_NOTHROW(tree_of_strings.add_left(LOVE, MOM));
  CHECK_NOTHROW(tree_of_strings.add_right(LOVE, DAD));
  auto it3 = tree_of_strings.begin_inorder();
  if (it3 != nullptr)
  {
    CHECK(*it3 == MOM);
    CHECK_FALSE(*it3 == SHALOM);
    ++it3;
    CHECK(*it3 == LOVE);
    ++it3;
    CHECK(*it3 == DAD);
  }

  BinaryTree<double> tree_of_doub;
  tree_of_doub.add_root(ONE_4);
  CHECK_NOTHROW(tree_of_doub.add_left(ONE_4, EIGHT_66));
  CHECK_NOTHROW(tree_of_doub.add_right(ONE_4, TWEN_3488));
  auto it4 = tree_of_doub.begin_inorder();
  if (it4 != nullptr)
  {
    CHECK(*it4 == EIGHT_66);
    CHECK_FALSE(*it4 == ONE_4);
    ++it4;
    CHECK(*it4 == ONE_4);
    ++it4;
    CHECK(*it4 == TWEN_3488);
  }
}
TEST_CASE("begin postorder method tests")
{

  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(ONE);
  CHECK_NOTHROW(tree_of_ints.add_left(ONE, EIGHT));
  CHECK_NOTHROW(tree_of_ints.add_right(ONE, TWO));
  auto it2 = tree_of_ints.begin_postorder();
  if (it2 != nullptr)
  {
    CHECK(*it2 == EIGHT);
    CHECK_FALSE(*it2 == TWO);
    ++it2;
    CHECK(*it2 == TWO);
    ++it2;
    CHECK(*it2 == ONE);
  }

  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root(LOVE);
  CHECK_NOTHROW(tree_of_strings.add_left(LOVE, MOM));
  CHECK_NOTHROW(tree_of_strings.add_right(LOVE, DAD));
  auto it3 = tree_of_strings.begin_postorder();
  if (it3 != nullptr)
  {
    CHECK(*it3 == MOM);
    CHECK_FALSE(*it3 == SHALOM);
    ++it3;
    CHECK(*it3 == DAD);
    ++it3;
    CHECK(*it3 == LOVE);
  }

  BinaryTree<double> tree_of_doub;
  tree_of_doub.add_root(ONE_4);
  CHECK_NOTHROW(tree_of_doub.add_left(ONE_4, EIGHT_66));
  CHECK_NOTHROW(tree_of_doub.add_right(ONE_4, TWEN_3488));
  auto it4 = tree_of_doub.begin_postorder();
  if (it4 != nullptr)
  {
    CHECK(*it4 == EIGHT_66);
    CHECK_FALSE(*it4 == ONE_4);
    ++it4;
    CHECK(*it4 == TWEN_3488);
    ++it4;
    CHECK(*it4 == ONE_4);
  }
}
