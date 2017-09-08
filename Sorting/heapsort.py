"""
Copyright (c) 2017 Oscar Albornoz. All rights reserved.
"""

import random
import time

def heap_sort(arr):
    max_heapify(arr)
    for end in reversed(range(len(arr))):
        arr[end], arr[0] = arr[0], arr[end]
        sift_down(arr,0,end-1)
    return arr

def max_heapify(arr):
    mid = (len(arr) >> 1)
    for i in reversed(range(mid)):
        sift_down(arr,i,len(arr)-1)

def sift_down(arr, father, end):
    while True:
        left_child = (father << 1) + 1
        right_child = left_child + 1

        if left_child > end:
            break

        if right_child > end:
            right_child = left_child

        if arr[left_child] >= arr[right_child]:
            greater_child = left_child
        else:
            greater_child = right_child

        if arr[father] >= arr[greater_child]:
                break

        arr[greater_child], arr[father] = arr[father], arr[greater_child]
        father = greater_child

def main():
    """
    Testing the function
    """
    random.seed(1)
    arr = list(random.randint(-5000, 100000) for i in range(100000))
    copy_one = copy_two = arr

    start = time.clock()
    copy_one = heap_sort(arr)
    print(time.clock() - start)

    start = time.clock()
    copy_two = sorted(copy_two)
    print(time.clock()-start)

    print(copy_one == copy_two)

if __name__ == "__main__":
    main()
