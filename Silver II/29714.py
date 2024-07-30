import sys

input = sys.stdin.readline

N = int(input())
N = list(map(int, input().split()))
아이스크림 = dict()
for i in N:
    아이스크림[i] = 아이스크림.get(i, 0) + 1

Q = int(input())

for _ in range(Q):
    A = list(map(int, input().split()))
    A = A[1:]
    B = list(map(int, input().split()))
    B = B[1:]

    먹을_아이스크림 = dict()
    for a in A:
        먹을_아이스크림[a] = 먹을_아이스크림.get(a, 0) + 1

    for key, item in 먹을_아이스크림.items():
        if 아이스크림.get(key, 0) < item:
            break
    else:
        # break 없이 완료
        for key, item in 먹을_아이스크림.items():
            아이스크림[key] = 아이스크림[key] - item
        for b in B:
            아이스크림[b] = 아이스크림.get(b, 0) + 1
        continue

ans = []

for key, item in 아이스크림.items():
    for _ in range(item):
        ans.append(str(key))

print(len(ans))
print(" ".join(ans))
