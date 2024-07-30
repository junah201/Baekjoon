from collections import deque
import sys

input = sys.stdin.readline

N = int(input())

words = [
    deque(input().split())
    for _ in range(N)
]

S = list(input().strip().split())

for s in S:
    for w in words:
        if w and s == w[0]:
            w.popleft()
            break
    else:
        print("Impossible")
        exit()

for w in words:
    if w:
        print("Impossible")
        exit()

print("Possible")
