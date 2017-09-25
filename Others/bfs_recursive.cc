// Copyright (c) 2017 Oscar Albornoz. All rights reserved. C++11 required

/* Oscar Albornoz V24584769 Laboratorio PR3

 Practica:
  1) Funcion recursiva que imprima todos los nodos de un arbol sin usar espacio adicional.
  2) Funcion que pode la menor cantidad de hojas necesarias para que un arbol sea completo.

*/

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;

struct Node {
  char key;
  Node* left = nullptr;
  Node* right = nullptr;
  explicit Node(char k) : key(k) {}
};

// make aleatory binary tree
Node* make_tree(int num);

void delete_tree(Node* node);
int height(Node* node);

// return height of tallest node that doesn't have child
int min_height(Node* node);

// print tree level by level using space O(n)
void bfs_queue(Node* node);

// print tree level by level using space O(1)
void bfs_rec(Node* node, int level, int height);
void bfs(Node* node);  // Wraper function of bfs_rec

// Pruning tree's branches to do it a complete tree
void poda_rec(Node* node, int level, int min_height);
void poda(Node* node);  // Wraper function of poda_rec


int main(int argc, char const *argv[]) {
  srand(time(0));
  Node* root = make_tree(20);

  // COMPARE OUTPUT BETWEEN STANDAR BFS ALGORITHM AND MY RECURSIVE WAY

  cout << "\nBFS space O(n): ";
  bfs_queue(root);

  cout << "\nBFS space O(1): ";
  bfs(root);

  delete_tree(root);

  // CONVETER A IMCOMPLETE TREE IN A COMPLETE TREE APRUNING ITS BRANCHES

  Node* a = new Node('A');
  Node* b  = new Node('B');
  Node* c  = new Node('C');
  Node* d  = new Node('D');
  Node* e  = new Node('E');
  Node* f  = new Node('F');
  Node* g  = new Node('G');

  a->left = b;
  a->right = c;
  b->left = d;
  c->left = e;
  c->right = f;
  d->right = g;

  /*
  Original tree:  ABCDEFG

       A
     /   \
    B     C
   /    /   \
  D    E     F
   \
    G

  Complete tree: ABC

       A
     /   \
    B     C

  */

  cout << "\nBFS: ";
  bfs(a);

  cout << "\nDoing it a complete tree: ";
  poda(a);

  bfs(a);

  cout << endl;

  delete_tree(a);
  return 0;
}

// =begin Relevant code

void bfs(Node* node) {
  int h = height(node);
  for (int level = h; level >= 1; --level) {
    bfs_rec(node, level, h);
  }
}

void bfs_rec(Node* node, int level, int height) {
  if (!node)
    return;

  if (level == height) {
    cout << node->key << ", ";
    return;
  }

  bfs_rec(node->left, level, height - 1);
  bfs_rec(node->right, level, height - 1);
}

void poda(Node* node) {
  if (!node)
    return;

  int min_h = min_height(node);
  poda_rec(node, 1, min_h);
}

void poda_rec(Node* node, int level, int min_h) {
  if (!node)
    return;

  if (level == min_h) {
    delete_tree(node->left);
    delete_tree(node->right);
    node->left = nullptr;
    node->right = nullptr;
    return;
  }

  poda_rec(node->left, level + 1, min_h);
  poda_rec(node->right, level + 1, min_h);
}

// Relevant code =end

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

void delete_tree(Node* node) {
  if (!node)
    return;

  delete_tree(node->left);
  delete_tree(node->right);

  delete node;
  node = nullptr;
}


int height(Node* node) {
  if (!node)
    return 0;
  return 1 + std::max(height(node->left), height(node->right));
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

int min_height(Node* node) {
  if (!node)
    return 0;

  return 1 + std::min(min_height(node->left), min_height(node->right));
}
