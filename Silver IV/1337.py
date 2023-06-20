import sys

N = int(sys.stdin.readline())
arr = [int(sys.stdin.readline()) for _ in range(N)]

arr.srot()

ans = 4

for idx, value in enumerate(arr[:N - 1]):
    ans = min(ans, arr[idx + 1] - value)

print(ans)
