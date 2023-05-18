N = int(input())
A = []
for _ in range(N):
    A.append(list(map(str, input().split())))

ans = {
    "0": 0,
    "1": 0
}


def get(x: int, y: int, idx: int):
    tmp = A[y][x]

    for ny in range(y, y + idx):
        for nx in range(x, x + idx):
            if tmp != A[ny][nx]:
                new_idx = idx // 2
                get(x, y, new_idx)
                get(x + new_idx, y, new_idx)
                get(x, y + new_idx, new_idx)
                get(x + new_idx, y + new_idx, new_idx)
                return

    ans[tmp] += 1


get(0, 0, N)

print(ans["0"])
print(ans["1"])
