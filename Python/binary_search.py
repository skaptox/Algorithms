"""
Copyright (c) 2017 Oscar Albornoz. All rights reserved.
"""

#To compare performance between recursive and iterative way of Binary Search Algorithm

import random
import time

#Recursive way

def binary_search_rec(lis, key, left=0, right=None):
    """Recursive way"""
    if right is None:
        right = len(lis)-1
    if left > right:
        return -1
    midle = (left+right) >> 1  # Divide by 2

    if lis[midle] == key:
        return midle
    if key < lis[midle]:
        return binary_search_rec(lis, key, left, midle-1)
    else:
        return binary_search_rec(lis, key, midle+1, right)

#Iterative way

def binary_search_it(lis, key, left=0, right=None):
    """Iterative way"""
    if right is None:
        right = len(lis)-1
    while left <= right:
        midle = (left+right) >> 1
        if key < lis[midle]:
            right = midle-1
        elif key > lis[midle]:
            left = midle+1
        else:
            return midle
    return -1

def main():
    """Testing"""

    random.seed(1)
    num_keys = int(1E+5) #100.000

    lis = list(range(num_keys))

    #Random keys

    keys = [random.randint(0, num_keys) for i in range(num_keys)]

    #Loking for those keys in the list

    index_1 = 0
    start = time.clock()
    for k in keys:
        index_1 += binary_search_rec(lis, k)
    print("Rec:", time.clock()-start)

    index_2 = 0
    start = time.clock()
    for k in keys:
        index_2 += binary_search_it(lis, k)

    print("It:", time.clock()-start)
    print("Did they return the same results?", index_1 == index_2)

if __name__ == '__main__':
    main()
