"""
The millionth Fibonacci using recursion with memoizing in lru_cache
"""
import time
from functools import lru_cache

@lru_cache(None)
def fibonacci(num):
    """
    The function exploits the fact that to calculate both F(2N) and F(2N-1) you
    only need to know F(num) and F(num-1).
    """
    if num in (0, 1):
        return 0 if num == 0 else 1
    if num & 1:  # if num is odd, it's faster than checking with modulo
        return fibonacci((num+1)//2 - 1) * (2*fibonacci((num+1)//2) - fibonacci((num+1)//2 - 1))
    result_1, result_2 = fibonacci(num//2 - 1), fibonacci(num//2)
    return result_1*result_1 + result_2*result_2

def main():
    """Testing the function"""
    start = time.time()
    result = fibonacci(1500000)
    end = time.time()
    print(result)
    print("Time: ", end - start)

if __name__ == '__main__':
    main()
