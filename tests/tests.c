#include "tests.h"

void run_tests() {
  run_add_tests();
  run_find_tests();
  run_min_tests();
}

void run_add_tests() {
  void (*func_ptr[])(tree_t *tree, int key, char *value) = {tree_add_r, tree_add};
  for (size_t i = 0; i < 2; ++i) {
    test_add1(func_ptr[i]);
    test_add2(func_ptr[i]);
    test_add3(func_ptr[i]);
  }
}

void test_add1(void (*add)(tree_t *tree, int key, char *value)) {
  printf("test_add1()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  add(&tree, 34, "Dima");
  add(&tree, 28, "Egor");

  assert(tree.count==3);
}

void test_add2(void (*add)(tree_t *tree, int key, char *value)) {
  printf("test_add2()\n");
  tree_t *tree = NULL;
  add(tree, 29, "Denis");
}

void test_add3(void (*add)(tree_t *tree, int key, char *value)) {
  printf("test_add3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  add(&tree, 34, "Dima1");
  add(&tree, 28, "Egor");
  add(&tree, 34, "Dima2");

  assert(tree.count==3);
}

void run_find_tests() {
  const node_t *(*funt_ptr[])(tree_t *tree, int key) = {tree_find, tree_find_r};
  for (size_t i = 0; i < 2; ++i) {
    test_find1(funt_ptr[i]);
    test_find2(funt_ptr[i]);
    test_find3(funt_ptr[i]);
    test_find4(funt_ptr[i]);
    test_find5(funt_ptr[i]);
  }
}

void test_find1(const node_t *(*find)(tree_t *tree, int key)) {
  printf("test_find1()\n");

  tree_t *tree = NULL;
  const node_t *r = find(tree, 29);
  assert(r==NULL);
}

void test_find2(const node_t *(*find)(tree_t *tree, int key)) {
  printf("test_find2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 35);
  assert(r==NULL);
}

void test_find3(const node_t *(*find)(tree_t *tree, int key)) {
  printf("test_find3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 29);

  assert(r->key==29);
  assert(strcmp(r->value, "Denis")==0);
}

void test_find4(const node_t *(*find)(tree_t *tree, int key)) {
  printf("test_find4()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 34);

  assert(r->key==34);
  assert(strcmp(r->value, "Dima1")==0);
}

void test_find5(const node_t *(*find)(tree_t *tree, int key)) {
  printf("test_find5()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 34, "Dima1");
  tree_add(&tree, 28, "Egor");

  const node_t *r = find(&tree, 28);

  assert(r->key==28);
  assert(strcmp(r->value, "Egor")==0);
}

void run_min_tests() {
  const node_t *(*funct_ptr[])(const tree_t *root) = {tree_min, tree_min_r};
  for (size_t i = 0; i < 1; ++i) {
    test_min1(funct_ptr[i]);
    test_min2(funct_ptr[i]);
    test_min3(funct_ptr[i]);
    test_min4(funct_ptr[i]);
  }
}

void test_min1(const node_t *(*min)(const tree_t *tree)) {
  printf("test_min1()\n");

  tree_t *tree = NULL;

  const node_t *result = min(tree);

  assert(result==NULL);
}

void test_min2(const node_t *(*min)(const tree_t *tree)) {
  printf("test_min2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  const node_t *r = min(&tree);

  assert(r->key==29);
  assert(strcmp(r->value, "Denis")==0);
}

void test_min3(const node_t *(*min)(const tree_t *tree)) {
  printf("test_min3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");

  const node_t *r = min(&tree);

  assert(r->key==28);
  assert(strcmp(r->value, "Egor")==0);
}

void test_min4(const node_t *(*min)(const tree_t *tree)) {
  printf("test_min4()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima");

  const node_t *r = min(&tree);

  assert(r->key==28);
  assert(strcmp(r->value, "Egor")==0);
}
