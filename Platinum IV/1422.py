# 1422 숫자의 신
# https://www.acmicpc.net/source/39238286

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

N, M = map(int, input().split())
Arr = []
for _ in range(N):
    Arr.append(input())

Sorted = sorted(Arr, key=cmp_to_key(cmp))

if Sorted[0] == "0":
    print(0)
else:
    if N == M:
        print("".join(Sorted))
    else:
        cnt = [1 for _ in range(N)]

        idx = 0
        max = len(Sorted[0])

        for i in range(1,N):
            if len(Sorted[i]) > max:
                max = len(Sorted[i])
                idx = i

        cnt[idx] += M - N

        for i in range(N):
            for _ in range(cnt[i]):
                print(Sorted[i], end="")

