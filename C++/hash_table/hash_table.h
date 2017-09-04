// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#ifndef _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_TABLE_H_
#define _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_TABLE_H_

#include <iostream>
#include <functional>

using std::cout;
using std::endl;

template<typename TKey, typename TValue>
class HashObject {
 public:
  HashObject() : key_(0), value_(0), next_(nullptr) {}
  HashObject(const TKey &k,const TValue &v) : key_(k), value_(v), next_(nullptr) {}

  HashObject(const HashObject<TKey, TValue>&) = delete;
  HashObject operator=(const HashObject<TKey, TValue>&) = delete;

  ~HashObject() {}
  inline TKey key() const { return key_;}
  inline TValue value() const { return value_;}
  inline HashObject<TKey, TValue>* next() const {return next_;}

  void set_value(const TValue &v) {value_ = v;}
  void set_next(HashObject<TKey, TValue> *n) { next_ = n;}
 private:
  TKey key_;
  TValue value_;
  HashObject *next_;
};

template<typename TKey, typename TValue>
class HashTable {
 public:
  explicit HashTable(const size_t s, std::function<size_t(TKey)>
    h = std::hash<TKey>());

  HashTable() = delete;
  HashTable (const HashTable<TKey, TValue>&) = delete;
  HashTable operator=(const HashObject<TKey, TValue>&) = delete;

  ~HashTable();

  inline size_t size() const {return size_;}

  bool exists(const TKey &k) const;
  size_t hash(const TKey &k) const;
  void add(const TKey &k, const TValue &v);
  void remove(const TKey &k);
  TValue get(const TKey &k) const;

  HashObject<TKey, TValue>* find(const TKey &k) const;

  void print_debug() const;

 private:
  HashObject<TKey, TValue> **data_;
  size_t size_;
  std::function<size_t(TKey)> hash_;
};

// Constructor by parameters

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable(const size_t s, std::function<size_t(TKey)> h)
: size_(s), hash_(h) {
  data_ = new HashObject<TKey, TValue>*[size_];
}

// Destructor

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::~HashTable(){
  for (int i = 0; i < size_; ++i) {
    if (data_[i]) {
      HashObject<TKey,TValue> *current = data_[i];
      while(current) {
        HashObject<TKey,TValue> *next = current->next();
        delete current;
        current = next;
        }
      }
    }
  delete [] data_;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::remove(const TKey &k) {
  size_t index = hash(k);

  if (data_[index]) {

    HashObject<TKey,TValue>* item = data_[index];
    HashObject<TKey,TValue>* prev = nullptr;

    while(item) {
      if (item->key() == k) {
        if(item->next()) {  // If there are least two items in the list
          if (prev) {  // If the item to delete is in the list's middle
            prev->set_next(item->next());
            delete item;
          } else {  // If the item to delete is the list's first
            prev = item->next();
            delete data_[index];
            data_[index] = prev;
          }
        } else {
          if (item == data_[index]) { // If there is only one element
            delete data_[index];
            data_[index] = nullptr;
          } else {
            prev->set_next(nullptr);
            delete item;  // If the item to delete is the last
          }
          break;
      }
    }
      prev = item;
      item = item->next();
    }
  }
}

// Hash function

template<typename TKey, typename TValue>
size_t HashTable<TKey, TValue>::hash(const TKey &k)
const {
  return hash_(k) % size_;
}

// Add item to table

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::add(const TKey &k, const TValue &v) {
  HashObject<TKey,TValue>* item = find(k);

  if(item) {
    item->set_value(v);  // If key already exists, update value
    return;
  }

  size_t index = hash(k);
  HashObject<TKey,TValue> *new_item = new HashObject<TKey,TValue>(k,v);

  if (not data_[index]) {
    data_[index] = new_item;
  } else {
    new_item->set_next(data_[index]);
    data_[index] = new_item;
  }
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::print_debug() const {
  for (int i = 0; i < size_; ++i) {
    if (data_[i]) {
      HashObject<TKey,TValue> *current = data_[i];
      while(current) {
        HashObject<TKey,TValue> *next = current->next();
        cout <<"Hash:" << hash(current->key()) << " Clave: " << current->key()
        << " Valor: " << current->value() << endl;
        current = next;
        }
      }
    }
}

template<typename TKey, typename TValue>
HashObject<TKey, TValue>* HashTable<TKey, TValue>::find(const TKey &k) const {
  size_t index = hash(k);

  if (data_[index]) {
    HashObject<TKey,TValue> *current = data_[index];
    while(current) {

      if (current->key() == k)
        return current;

      current = current->next();
    }
  }
  return nullptr;
}

template<typename TKey, typename TValue>
TValue HashTable<TKey, TValue>::get(const TKey &k) const {
  HashObject<TKey,TValue>* item = find(k);
  if (item) {
    return item->value();
  }
  return TValue();
}

template<typename TKey, typename TValue>
bool HashTable<TKey, TValue>::exists(const TKey &k) const {
  return find(k) != nullptr;
}

//

#endif  // _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_TABLE_H_
