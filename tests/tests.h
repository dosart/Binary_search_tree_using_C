#ifndef BINARY_SEARCH_TREE_TESTS_TESTS_H_
#define BINARY_SEARCH_TREE_TESTS_TESTS_H_

#include "binary_tree.h"

#include <assert.h>
#include <string.h>

void run_tests();

void run_add_tests();

void test_add1(void (*add)(tree_t *tree, int key, char *value));
void test_add2(void (*add)(tree_t *tree, int key, char *value));
void test_add3(void (*add)(tree_t *tree, int key, char *value));

void run_find_tests();

void test_find1(const node_t *(*find)(tree_t *tree, int key));
void test_find2(const node_t *(*find)(tree_t *tree, int key));
void test_find3(const node_t *(*find)(tree_t *tree, int key));
void test_find4(const node_t *(*find)(tree_t *tree, int key));
void test_find5(const node_t *(*find)(tree_t *tree, int key));

void run_min_tests();

void test_min1(const node_t *(*min)(const tree_t *tree));
void test_min2(const node_t *(*min)(const tree_t *tree));
void test_min3(const node_t *(*min)(const tree_t *tree));
void test_min4(const node_t *(*min)(const tree_t *tree));

#endif //BINARY_SEARCH_TREE_TESTS_TESTS_H_
