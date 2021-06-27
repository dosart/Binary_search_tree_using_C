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

static node_t *add_r(node_t *root, int key, char *value, size_t* count);

void tree_add_r(tree_t *tree, int key, char *value) {
  if (tree) {
    tree->root = add_r(tree->root, key, value, &tree->count);
  }
}

static node_t *add_r(node_t *root, int key, char *value, size_t* count) {
  if (root==NULL) {
    *count = *count + 1;
    return make_node(key, value);
  } else if (key > root->key) {
    root->right = add_r(root->right, key, value, count);
  } else if (key < root->key) {
    root->left = add_r(root->left, key, value, count);
  }
  return root;
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

const node_t *tree_find(tree_t *tree, int key) {
  if (tree) {
    node_t *curr = NULL;
    for (curr = tree->root; curr!=NULL;) {
      if (curr->key==key) {
        break;
      } else if (key > curr->key) {
        curr = curr->right;
      } else {
        curr = curr->left;
      }
    }
    return curr;
  }
  return NULL;
}

static const node_t *find_r(node_t *root, int key);

const node_t *tree_find_r(tree_t *tree, int key) {
  if (tree) {
    return find_r(tree->root, key);
  }
  return NULL;
}

const node_t *find_r(node_t *root, int key) {
  if (root==NULL) {
    return NULL;
  }
  if (root->key==key) {
    return root;
  }
  if (key > root->key) {
    return find_r(root->right, key);
  } else {
    return find_r(root->left, key);
  }
}
