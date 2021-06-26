#include "binary_tree.h"

void tree_init(tree_t *table) {
  if (table) {
    table->count = 0;
  }
}

static node_t *make_node(int key, char *value);

void tree_add(tree_t *tree, int key, char *value) {
  if (tree) {
    
  }
}

static node_t *make_node(int key, char *value) {
  node_t *node = (node_t *) malloc(sizeof(node_t *));
  if (node) {
    node->key = key;
    node->value = value;
    node->left = node->right = NULL;
  }
  return node;
}
