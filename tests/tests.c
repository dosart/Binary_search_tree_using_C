#include "tests.h"

void run_tests() {
  test_add1();
  test_add2();
  test_add3();

}

void test_add1() {
  printf("test_add1()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  tree_add(&tree, 34, "Dima");
  tree_add(&tree, 28, "Egor");

  assert(tree.count==3);
}

void test_add2() {
  printf("test_add2()\n");

  tree_t *tree = NULL;

  tree_add(tree, 29, "Denis");
}

void test_add3() {
  printf("test_add3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima2");

  assert(tree.count==3);
}
