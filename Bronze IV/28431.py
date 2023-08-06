import sys
input = sys.stdin.readline

A = [
    int(input()) for _ in range(5)
]

for i in A:
    if A.count(i) % 2 == 1:
        print(i)
        break
