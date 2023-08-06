import sys
input = sys.stdin.readline

N = int(input())

A = [
    input().rstrip() for _ in range(N)
]

idx = A.index("?")

M = int(input())
B = [
    input().rstrip() for _ in range(M)
]

prev = None
if idx != 0:
    prev = A[idx - 1]

next = None
if idx != N - 1:
    next = A[idx + 1]

set_A = set(A)

for i in B:
    if i in set_A:
        continue
    if prev != None:
        if prev[-1] != i[0]:
            continue
    if next != None:
        if next[0] != i[-1]:
            continue

    print(i)
    break
