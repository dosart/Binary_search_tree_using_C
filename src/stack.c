#include "stack.h"

void stack_init(stack_t *stack, size_t capacity) {
  if (stack) {
    stack->data = (node_t **) malloc(sizeof(node_t *)*capacity);
    if (stack->data) {
      stack->capacity = capacity;
      stack->count = 0;
    }
  }
}

static void maybe_reduce_capacity(stack_t *stack);

void stack_push(stack_t *stack, node_t *node) {
  if (stack) {
    maybe_reduce_capacity(stack);
    stack->data[stack->count++] = node;
  }
}

static void maybe_reduce_capacity(stack_t *stack) {
  if (stack->count >= stack->capacity) {
    stack->capacity = stack->capacity*2;
    stack->data = (node_t **) realloc(stack->data, sizeof(node_t *)*stack->capacity);
  }
}

node_t *stack_pop(stack_t *stack) {
  if (stack && stack->count > 0) {
    return stack->data[--stack->count];
  }
  return NULL;
}
