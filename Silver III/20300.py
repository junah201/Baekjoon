import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
T = list(map(int, input().split()))

T.sort()
T = deque(T)

ans = 0

if len(T) % 2 == 1:
    ans = max(ans, T.pop())

while T:
    a, b = T.pop(), T.popleft()
    ans = max(ans, a + b)

print(ans)
