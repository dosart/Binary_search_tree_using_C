#include "tests.h"

void run_tests() {
  test_add1();
  test_add2();
  test_add3();

  test_find1();
  test_find2();
  test_find3();
  test_find4();
  test_find5();
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

void test_find1() {
  printf("test_find1()\n");

  tree_t *tree = NULL;
  const node_t *find = tree_find(tree, 29);
  assert(find==NULL);
}

void test_find2() {
  printf("test_find2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *find = tree_find(&tree, 35);

  assert(find==NULL);
}

void test_find3() {
  printf("test_find3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *find = tree_find(&tree, 29);

  assert(find->key==29);
  assert(strcmp(find->value, "Denis")==0);
}

void test_find4() {
  printf("test_find4()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *find = tree_find(&tree, 34);

  assert(find->key==34);
  assert(strcmp(find->value, "Dima1")==0);
}

void test_find5() {
  printf("test_find5()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *find = tree_find(&tree, 28);

  assert(find->key==28);
  assert(strcmp(find->value, "Egor")==0);
}
