/*!
@file
@brief  Header file for Simple binary search tree
This file contains the definition of the data structure binary search tree (naive implementation)
*/
#ifndef BINARY_SEARCH_TREE_INCLUDE_BINARY_TREE_H_
#define BINARY_SEARCH_TREE_INCLUDE_BINARY_TREE_H_

#include <stddef.h>
#include <malloc.h>

/**
 * @defgroup binary_search_tree
 *
 * @brief Item of binary search tree
 *
 * @warning This structure created only for educational goals
 */
typedef struct tree_node_t {
  char *value;
  struct tree_node_t *left;
  struct tree_node_t *right;
  int key;
} node_t;

/**
 * @ingroup binary_search_tree
 *
 * @brief binary search tree data structure
 *
 * @warning This structure created only for educational goals
 */
typedef struct tree_t {
  node_t *root;
  size_t count;
} tree_t;

/**
 * @ingroup binary_search_tree
 *
 * @brief Init  binary search tree data structure.
 *
 * @param tree Pointer to binary search tree data structure.
 * @param key Key of root node.
 * @param value Value of root node.
 */
void tree_init(tree_t *table, int key, char *value);

/**
 * @ingroup binary_search_tree
 *
 * @brief Add the given key and object to tree(iterative version).
 *
 * @param tree Pointer to binary search tree data structure.
 * @param key Key for value.
 * @param value Value by key.
 */
void tree_add(tree_t *tree, int key, char *value);

/**
 * @ingroup binary_search_tree
 *
 * @brief Add the given key and object to tree(recursive version).
 *
 * @param tree Pointer to binary search tree data structure.
 * @param key Key for value.
 * @param value Value by key.
 */
void tree_add_r(tree_t *tree, int key, char *value);

/**
 * @ingroup binary_search_tree
 *
 * @brief Finds key in tree(iterative version).
 *
 * @param tree Pointer to binary search tree data structure.
 * @param key Key for find.
 *
 * @returns founded node or NULL if not found
 */
const node_t* tree_find(tree_t *tree, int key);

/**
 * @ingroup binary_search_tree
 *
 * @brief Finds key in tree(recursive version).
 *
 * @param tree Pointer to binary search tree data structure.
 * @param key Key for find.
 *
 * @returns founded node or NULL if not found
 */
const node_t* tree_find_r(tree_t *tree, int key);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns node with min key(iterative version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns founded node or NULL if not found
 */
const node_t *tree_min(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns node with min key(recursive version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns founded node or NULL if not found
 */
const node_t *tree_min_r(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns node with max key(iterative version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns founded node or NULL if not found
 */
const node_t *tree_max(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns node with max key(recursive version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns founded node or NULL if not found
 */
const node_t *tree_max_r(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns the height of the tree in nodes, 0 if empty (iterative version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns height of three
 */
size_t tree_height(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns the height of the tree in nodes, 0 if empty (recursive version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns height of three
 */
size_t tree_height_r(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns the number of nodes stored in the tree(iterative version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns count of nodes
 */
size_t tree_node_count(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns the number of nodes stored in the tree(recursive version).
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns count of nodes
 */
size_t tree_node_count_r(const tree_t *tree);

/**
 * @ingroup binary_search_tree
 *
 * @brief Returns node that contains next key.
 *
 * @param tree Pointer to binary search tree data structure.
 *
 * @returns ode that contains next key
 */
const node_t *tree_successor(const tree_t *tree, int key);

#endif //BINARY_SEARCH_TREE_INCLUDE_BINARY_TREE_H_
