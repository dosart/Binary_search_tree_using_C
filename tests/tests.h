#ifndef BINARY_SEARCH_TREE_TESTS_TESTS_H_
#define BINARY_SEARCH_TREE_TESTS_TESTS_H_

#include "binary_tree.h"

#include <assert.h>
#include <string.h>

void run_tests();

void test_add1();
void test_add2();
void test_add3();

void run_find_tests();

void test_find1(const node_t* (*find) (tree_t *tree, int key));
void test_find2(const node_t* (*find) (tree_t *tree, int key));
void test_find3(const node_t* (*find) (tree_t *tree, int key));
void test_find4(const node_t* (*find) (tree_t *tree, int key));
void test_find5(const node_t* (*find) (tree_t *tree, int key));

#endif //BINARY_SEARCH_TREE_TESTS_TESTS_H_
