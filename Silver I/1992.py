N = int(input())
A = []
for _ in range(N):
    A.append(list(input()))


def get(x: int, y: int, idx: int):
    tmp = A[y][x]

    for ny in range(y, y + idx):
        for nx in range(x, x + idx):
            if tmp != A[ny][nx]:
                new_idx = idx // 2
                return f"({get(x, y, new_idx)}{get(x + new_idx, y, new_idx)}{get(x, y + new_idx, new_idx)}{get(x + new_idx, y + new_idx, new_idx)})"

    return tmp


print(f"{get(0, 0, N)}")
