//
// Created by dosart on 7/5/21.
//

#ifndef BINARY_SEARCH_TREE_INCLUDE_STACK_H_
#define BINARY_SEARCH_TREE_INCLUDE_STACK_H_

#include "binary_tree.h"

/**
 * @defgroup stack
 *
 * @brief Stack Implementation  for DFS(using dynamic array)
 *
 * @warning This structure created only for educational goals
 */
typedef struct stack_t {
  node_t **data;
  size_t count;
  size_t capacity;
} stack_t;

/**
 * @ingroup stack
 *
 * @brief Init stack data structure.
 *
 * @param stack Pointer to stack data structure.
 * @param capacity Capacity of stack
 */
void stack_init(stack_t *stack, size_t capacity);

/**
 * @ingroup stack
 *
 * @brief Adds node in stack
 *
 * @param stack Stack data structure.
 * @param node Element for added in stack.
 */
void stack_push(stack_t *stack, node_t *node);

/**
 * @ingroup stack
 *
 * @brief Extract node from stack
 *
 * @param stack Stack data structure.
 *
 * @returns node Element of  stack.
 */
node_t *stack_pop(stack_t *stack);

/**
 * @ingroup stack
 *
 * @brief Free memory in stack_item_t.
 *
 * @param s Pointer to stack.
 */
void stack_free(stack_t *stack);

#endif //BINARY_SEARCH_TREE_INCLUDE_STACK_H_
