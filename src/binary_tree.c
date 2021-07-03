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

static node_t *add_r(node_t *root, int key, char *value, size_t *count);

void tree_add_r(tree_t *tree, int key, char *value) {
  if (tree) {
    tree->root = add_r(tree->root, key, value, &tree->count);
  }
}

static node_t *add_r(node_t *root, int key, char *value, size_t *count) {
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

static const node_t *min(const node_t *root);

const node_t *tree_min(const tree_t *tree) {
  if (tree) {
    return min(tree->root);
  }
  return NULL;
}

const node_t *min(const node_t *root) {
  while (root->left!=NULL) {
    root = root->left;
  }
  return root;
}

static const node_t *min_r(const node_t *root);

const node_t *tree_min_r(const tree_t *tree) {
  if (tree) {
    return min_r(tree->root);
  }
  return NULL;
}

static const node_t *min_r(const node_t *root) {
  if (root->left)
    return min_r(root->left);
  return root;
}

const node_t *tree_max(const tree_t *tree) {
  if (tree) {
    node_t *curr = tree->root;
    while (curr->right) {
      curr = curr->right;
    }
    return curr;
  }
  return NULL;
}

static const node_t *max_r(node_t *root);

const node_t *tree_max_r(const tree_t *tree) {
  if (tree) {
    return max_r(tree->root);
  }
  return NULL;
}

static const node_t *max_r(node_t *root) {
  if (root->right) {
    return max_r(root->right);
  }
  return root;
}

static size_t left_height(const node_t *root);
static size_t right_height(const node_t *root);

static size_t max(size_t x, size_t y);

size_t tree_height(const tree_t *tree) {
  if (tree) {
    return 1 + max(left_height(tree->root->left), right_height(tree->root->right));
  }
  return 0;
}

static size_t max(size_t x, size_t y) {
  return x > y ? x : y;
}

static size_t height_r(const node_t *tree);

size_t tree_height_r(const tree_t *tree) {
  if (tree) {
    return height_r(tree->root);
  }
  return 0;
}

size_t tree_node_count(const tree_t *tree) {
  if (tree) {
    return 1 + left_height(tree->root->left) + right_height(tree->root->right);
  }
  return 0;
}

static size_t node_count_r(const node_t *tree);

size_t tree_node_count_r(const tree_t *tree) {
  if (tree) {
    return node_count_r(tree->root);
  }
  return 0;
}

static size_t left_height(const node_t *root) {
  if (root) {
    size_t count = 1;
    while (root->left) {
      root = root->left;
      ++count;
    }
    return count;
  }
  return 0;
}

static size_t right_height(const node_t *root) {
  if (root) {
    size_t count = 1;
    while (root->right) {
      root = root->right;
      ++count;
    }
    return count;
  }
  return 0;
}

static size_t height_r(const node_t *tree) {
  if (tree) {
    return 1 + max(height_r(tree->left), height_r(tree->right));
  }
  return 0;
}

static size_t node_count_r(const node_t *tree) {
  if (tree==NULL) {
    return 0;
  }
  return 1 + node_count_r(tree->left) + node_count_r(tree->right);
}

const node_t *tree_successor(const tree_t *tree, int key) {
  node_t *successor = NULL;
  if (tree) {
    node_t *root = tree->root;
    while (root) {
      if (key < root->key) {
        successor = root;
        root = root->left;
      } else if (key > root->key) {
        root = root->right;
      } else {
        if (root->right)
          return min(root->right);
        return successor;
      }
    }
    return successor;
  }
  return successor;
}

const node_t *tree_predecessor(const tree_t *tree, int key) {
  node_t *predecessor = NULL;
  if (tree) {
    node_t *root = tree->root;
    while (root) {
      if (key < root->key) {
        root = root->left;
      } else if (key > root->key) {
        predecessor = root;
        root = root->right;
      } else {
        if (root->left) {
          return max_r(root->left);
        }
        return predecessor;
      }
    }
    return predecessor;
  }
  return predecessor;
}

