import sys
input = sys.stdin.readline

N = int(input())

_ = int(input())

A = [
    int(input()) - 1 for _ in range(N - 1)
]

B = set()

for i in A:
    for j in B:
        if i % j == 0:
            break
    else:
        B.add(i)

print(len(B))
