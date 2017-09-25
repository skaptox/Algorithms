// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <time.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <chrono>

using std::cout;
using std::endl;

struct Node {
  char key;
  Node* left = nullptr;
  Node* right = nullptr;
  explicit Node(char k) : key(k) {}
};

Node* make_tree(int num);
int height(Node* node);

void bfs_queue(Node* node);  // To compare results
void bfs_rec(Node* node, int level, int height);
void bfs_recursive(Node* node);
void delete_tree(Node* node);

int main(int argc, char const *argv[]) {
  srand(time(0));
  Node* root = make_tree(10);

  clock_t a,b;

  a = clock();
  bfs_queue(root);
  b = clock();

  cout << "Time BFS space O(n): " << (double)(b-a) / CLOCKS_PER_SEC;
  cout << endl;

  a = clock();
  bfs_recursive(root);
  b = clock();

  cout << "Time BFS space O(1): " << (double)(b-a) / CLOCKS_PER_SEC;
  cout << endl;

  delete_tree(root);
  return 0;
}

Node* make_tree(int num) {
  if (num < 1)
    return nullptr;
  Node* node = new Node(rand() % 25 + 65);
  int i = rand() % num;
  node->left = make_tree(i);
  node->right = make_tree(num - i - 1);
  return node;
}

int height(Node* node) {
  if (!node)
    return 0;
  return 1 + std::max(height(node->left), height(node->right));
}

void bfs_queue(Node* node) {
  if (!node)
    return;

  std::queue<Node*> que;
  que.push(node);

  while (!que.empty()) {
    Node* cur = que.front();
    que.pop();

    cout << cur->key << ", ";

    if (cur->left)
      que.push(cur->left);
    if (cur->right)
      que.push(cur->right);
  }
}

void bfs_rec(Node* node, int level, int h) {
  if (level == h) {
    cout << node->key << ", ";
    return;
  }
  if (node->left)
    bfs_rec(node->left, level, h-1);

  if (node->right)
    bfs_rec(node->right, level, h-1);
}

void bfs_recursive(Node* node) {
  int h = height(node);
  for (int level = h; level >= 1; --level) {
    bfs_rec(node, level, h);
  }
}

void delete_tree(Node* node) {
  if (!node)
    return;
  if (node->left)
    delete_tree(node->left);

  if (node->right)
    delete_tree(node->right);

  delete node;
}
