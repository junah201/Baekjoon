import sys

input = sys.stdin.readline

N, S, R = map(int, input().split())
손상된팀 = list(map(int, input().split()))
여분팀 = list(map(int, input().split()))


A = [
    1 for _ in range(N)
]

for i in 손상된팀:
    A[i - 1] -= 1

for i in 여분팀:
    A[i - 1] += 1

ans = 0


for index in range(N):
    val = A[index]

    if val != 0:
        continue

    try:
        if A[index - 1] == 2 and index != 0:
            A[index - 1] = 1
            A[index] = 1
            continue
    except IndexError as e:
        pass

    try:
        if A[index + 1] == 2:
            A[index + 1] = 1
            A[index] = 1
            continue
    except IndexError as e:
        pass

    ans += 1

print(ans)
