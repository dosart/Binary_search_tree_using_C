#include "tests.h"

void run_tests() {
  run_add_tests();
  run_find_tests();
}

void run_add_tests() {
  void (*func_ptr[]) (tree_t *tree, int key, char *value) = {tree_add_r, tree_add};
  for (size_t i = 0; i < 2; ++i) {
    test_add1(func_ptr[i]);
    test_add2(func_ptr[i]);
    test_add3(func_ptr[i]);
  }
}

void test_add1(void (*add) (tree_t *tree, int key, char *value)) {
  printf("test_add1()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  add(&tree, 34, "Dima");
  add(&tree, 28, "Egor");

  assert(tree.count==3);
}

void test_add2(void (*add) (tree_t *tree, int key, char *value)) {
  printf("test_add2()\n");
  tree_t *tree = NULL;
  add(tree, 29, "Denis");
}

void test_add3(void (*add) (tree_t *tree, int key, char *value)) {
  printf("test_add3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  add(&tree, 34, "Dima1");
  add(&tree, 28, "Egor");
  add(&tree, 34, "Dima2");

  assert(tree.count==3);
}

void run_find_tests() {
  const node_t* (*functptr[])(tree_t *tree, int key) = {tree_find, tree_find_r};
  for (size_t i = 0; i < 2; ++i) {
    test_find1(functptr[i]);
    test_find2(functptr[i]);
    test_find3(functptr[i]);
    test_find4(functptr[i]);
    test_find5(functptr[i]);
  }
}

void test_find1(const node_t* (*find) (tree_t *tree, int key)) {
  printf("test_find1()\n");

  tree_t *tree = NULL;
  const node_t *r= find(tree, 29);
  assert(r==NULL);
}

void test_find2(const node_t* (*find) (tree_t *tree, int key)) {
  printf("test_find2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 35);
  assert(r==NULL);
}

void test_find3(const node_t* (*find) (tree_t *tree, int key)) {
  printf("test_find3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 29);

  assert(r->key==29);
  assert(strcmp(r->value, "Denis")==0);
}

void test_find4(const node_t* (*find) (tree_t *tree, int key)) {
  printf("test_find4()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 34);

  assert(r->key==34);
  assert(strcmp(r->value, "Dima1")==0);
}

void test_find5(const node_t* (*find) (tree_t *tree, int key)) {
  printf("test_find5()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r= find(&tree, 28);

  assert(r->key==28);
  assert(strcmp(r->value, "Egor")==0);
}
