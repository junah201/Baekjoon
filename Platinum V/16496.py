# 16496 큰 수 만들기
# https://www.acmicpc.net/source/39237525

from functools import cmp_to_key

def cmp(a : str, b : str):
    if a == "0":
        return 1
    if b == "0":
        return -1
    
    is_a = True
    is_b = True
    
    idx_a = 0
    idx_b = 0

    len_a = len(a)
    len_b = len(b)

    while idx_a != len_a + len_b:
        if idx_a == len_a:
            is_a = 0
        if idx_b == len_b:
            is_b = 0

        if is_a:
            temp_a = a[idx_a]
        else:
            temp_a = b[idx_a - len_a]
        idx_a += 1

        if is_b:
            temp_b = b[idx_b]
        else:
            temp_b = a[idx_b - len_b]
        idx_b += 1

        if temp_a > temp_b:
            return -1
        elif temp_a < temp_b:
            return 1

    return 0

N = int(input())
Arr = map(str, input().split())

Sorted = sorted(Arr, key=cmp_to_key(cmp))

if Sorted[0] == "0":
    print(0)
else:
    print("".join(Sorted))
