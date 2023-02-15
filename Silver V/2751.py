import sys

N = int(sys.stdin.readline())
Arr = []
for _ in range(N):
    Arr.append(int(sys.stdin.readline()))

Arr.sort()

for i in Arr:
    print(i)
