// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#ifndef _HOME_OSCAR_PRACTICES_CPP_LINKED_LIST_LIST_H_
#define _HOME_OSCAR_PRACTICES_CPP_LINKED_LIST_LIST_H_

#include "Node.h"

#include <thread>
#include <iostream>

using namespace std;

template<typename T>
class List {
 private:
  Node<T> *head;
  Node<T> *tail;
  size_t size_;

 public:
  List() : head(nullptr), tail(nullptr), size_(0) {}
  ~List() {std::cout<<"Destructor de List";
  }
  inline bool is_empty() {return head == nullptr;}
  inline size_t size() {return size_;}

  inline T back() {
    if (tail != nullptr)
      return tail->value();
    return 0;
  }

  inline T front() {
    if (head != nullptr)
      return head->value();
    return 0;
  }

  bool push_back(T val) {
    Node<T> *new_node = new Node<T>(val);
    if (is_empty()) {
      head = tail = new_node;  // Both point to single node
    } else if (head == tail) {
      head->set_next(new_node); // First node point to second node
      tail = head->next();  // Tail point to second node
    } else {
      tail->set_next(new_node);  // Last node point to new last node
      tail = tail->next();  // Tail point to new last node
    }
    size_++;
    return true;
  }

  void pop_back() {
    if (size_) {
      Node<T> *current = head;
      auto tail_ = tail;

      while (current->next() != tail_ and current->next() != nullptr)
          current = current->next();

      delete tail;

      tail = current;
      size_--;
    }
  }

  bool insert(size_t pos, T val) {
    if (pos < size()) {
      size_t idx = 0;

      Node<T> *current = head;
      Node<T> *new_node = new Node<T>(val);

      while(idx < pos and current->next()) {
        current = current->next();
        idx++;
      }
      new_node->set_next(current->next());
      current->set_next(new_node);
      }
    return false;
  }
};

#endif  // _HOME_OSCAR_PRACTICES_CPP_LINKED_LIST_LIST_H_



