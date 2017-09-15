// Copyright (c) 2017 Oscar Albornoz. All rights reserved.


#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iostream>

template <typename T, typename Comp = std::less<T>>
void heap_sort(T* array, int size, const Comp &cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void heapify(T* array, int size, const Comp &cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void sift_down(T* array, int parent, int end, const Comp &cmp = Comp());

using std::cout;
using std::endl;

const int kSize = 1000000;

int main(int argc, char const *argv[]) {
  int arr[kSize];

  for (int i = 0; i < kSize; ++i) {
    arr[i] = rand() % kSize;  // NOLINT
  }

  cout << "Sorting " << kSize << " elements" << endl;

  clock_t begin = clock();

  heap_sort(arr, kSize, [](int f, int s) {return f > s;});

  clock_t end = clock();
  double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

  cout << "Time: " << elapsed_secs << endl;

  return 0;
}

template <typename T, typename Comp>
void heap_sort(T* array, int size, const Comp &cmp) {
  heapify(array, size, cmp);

  for (int end = size - 1; end >= 0; --end) {
    std::swap(array[0], array[end]);
    sift_down(array, 0, end - 1, cmp);
  }
}

template <typename T, typename Comp>
void heapify(T* array, int size, const Comp &cmp) {
  for (int i = size / 2 - 1; i >= 0; --i) {
    sift_down(array, i, size - 1, cmp);
  }
}

template <typename T, typename Comp>
void sift_down(T* array, int parent, int end, const Comp &cmp) {
  int left_child, right_child, swappable_child;

  while ((left_child = (parent << 1) + 1) <= end) {
    right_child = left_child + 1;

    if (right_child > end)
      right_child = left_child;

    swappable_child = cmp(array[right_child], array[left_child]) ?
      left_child : right_child;

    if (cmp(array[swappable_child], array[parent]))
      break;

    std::swap(array[parent], array[swappable_child]);
    parent = swappable_child;
  }
}
