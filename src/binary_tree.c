#include "binary_tree.h"

static node_t *make_node(int key, char *value);

void tree_init(tree_t *table, int key, char *value) {
  if (table) {
    table->root = make_node(key, value);
    table->count = 1;
  }
}

void tree_add(tree_t *tree, int key, char *value) {
  if (tree) {
    node_t *parent, *curr;
    for (curr = tree->root; curr!=NULL;) {
      parent = curr;
      if (key > curr->key) {
        curr = curr->right;
      } else if (key < curr->key) {
        curr = curr->left;
      } else
        return;
    }
    node_t *new_node = make_node(key, value);
    if (key > parent->key) {
      parent->right = new_node;
    } else {
      parent->left = new_node;
    }
    ++tree->count;
  }
}

static node_t *make_node(int key, char *value) {
  node_t *node = (node_t *) malloc(sizeof(node_t));
  if (node) {
    node->key = key;
    node->value = value;
    node->left = node->right = NULL;
  }
  return node;
}
