import sys
input = sys.stdin.readline

n = int(input())

ans = set()


def get(idx: int, sum: int):
    if idx == n:
        ans.add(sum)
        return

    for i in range(1, 10):
        get(idx + 1, sum * i)


get(0, 1)

print(len(ans))
