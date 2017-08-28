"""
Copyright (c) 2017 Oscar Albornoz. All rights reserved.
"""

import random
import time

def heap_sort(arr):
    """ Making the heap """
    for c_idx, child in enumerate(arr):
        while True:
            father = (c_idx >> 1) - (0 if c_idx  & 1 else 1)
            if father < 0 or arr[father] >= child:
                break
            arr[c_idx], arr[father] = arr[father], arr[c_idx]
            c_idx = father

    #Sorting the array
    for i in range(1, len(arr)):
        ult = len(arr) - i
        arr[ult], arr[0] = arr[0], arr[ult]
        father = 0
        while True:
            left_child = (father<<1) + 1
            right_child = left_child + 1

            if left_child >= ult:
                break

            if right_child >= ult:
                right_child = left_child

            child = left_child if arr[left_child] >= arr[right_child] else right_child

            if arr[father] >= arr[child]:
                break

            arr[child], arr[father] = arr[father], arr[child]
            father = child
    return arr

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
