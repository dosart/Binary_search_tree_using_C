#include "tests.h"

void run_tests() {
  run_add_tests();
  run_find_tests();
  run_min_tests();
  run_max_tests();
  run_height_tests();
  run_node_count_tests();
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
  for (size_t i = 0; i < 2; ++i) {
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

void run_max_tests() {
  const node_t *(*funct_ptr[])(const tree_t *root) = {tree_max, tree_max_r};
  for (size_t i = 0; i < 2; ++i) {
    test_max1(funct_ptr[i]);
    test_max2(funct_ptr[i]);
    test_max3(funct_ptr[i]);
    test_max4(funct_ptr[i]);
  }
}

void test_max1(const node_t *(*max)(const tree_t *tree)) {
  printf("test_max1()\n");

  tree_t *tree = NULL;
  const node_t *result = max(tree);
  assert(result==NULL);
}

void test_max2(const node_t *(*max)(const tree_t *tree)) {
  printf("test_max2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  const node_t *r = max(&tree);

  assert(r->key==29);
  assert(strcmp(r->value, "Denis")==0);
}

void test_max3(const node_t *(*max)(const tree_t *tree)) {
  printf("test_max3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");

  const node_t *r = max(&tree);

  assert(r->key==29);
  assert(strcmp(r->value, "Denis")==0);
}

void test_max4(const node_t *(*max)(const tree_t *tree)) {
  printf("test_max4()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima");

  const node_t *r = max(&tree);

  assert(r->key==34);
  assert(strcmp(r->value, "Dima")==0);
}

void run_height_tests() {
  size_t(*func_ptr[])(
  const tree_t *tree) = { tree_height, tree_height_r };
  for (size_t i = 0; i < 2; ++i) {
    test_height1(func_ptr[i]);
    test_height2(func_ptr[i]);
    test_height3(func_ptr[i]);
    test_height4(func_ptr[i]);
  }

}

void test_height1(size_t (*height)(const tree_t *tree)) {
  printf("test_height1()\n");

  tree_t *tree = NULL;

  size_t r = height(tree);

  assert(r==0);
}

void test_height2(size_t (*height)(const tree_t *tree)) {
  printf("test_height2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  size_t r = height(&tree);

  assert(r==1);
}

void test_height3(size_t (*height)(const tree_t *tree)) {
  printf("test_height3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima");

  size_t r = height(&tree);

  assert(r==2);
}

void test_height4(size_t (*height)(const tree_t *tree)) {
  printf("test_height4()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima");
  tree_add(&tree, 36, "Gena");

  size_t r = height(&tree);

  assert(r==3);
}

void run_node_count_tests() {
  size_t(*func_ptr[])(
  const tree_t *tree) = { tree_node_count_r, tree_node_count };
  for (size_t i = 0; i < 2; ++i) {
    test_node_count1(func_ptr[i]);
    test_node_count2(func_ptr[i]);
    test_node_count3(func_ptr[i]);
    test_node_count4(func_ptr[i]);
  }
}

void test_node_count1(size_t (*node_count)(const tree_t *tree)) {
  printf("test_node_count1()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");

  size_t r = node_count(&tree);

  assert(r==1);
}

void test_node_count2(size_t (*node_count)(const tree_t *tree)) {
  printf("test_node_count2()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima");

  size_t r = node_count(&tree);

  assert(r==3);
}

void test_node_count3(size_t (*node_count)(const tree_t *tree)) {
  printf("test_node_count3()\n");

  tree_t tree;
  tree_init(&tree, 29, "Denis");
  tree_add(&tree, 28, "Egor");
  tree_add(&tree, 34, "Dima");
  tree_add(&tree, 22, "Alex");

  size_t r = node_count(&tree);

  assert(r==4);
}

void test_node_count4(size_t (*node_count)(const tree_t *tree)) {
  printf("test_node_count4()\n");

  tree_t *tree = NULL;

  size_t r = node_count(tree);

  assert(r==0);
}

