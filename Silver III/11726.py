N = int(input())

DP = [-1 for i in range(N + 2)]

DP[0] = 0
DP[1] = 1
DP[2] = 2


def get(idx: int):
    global DP

    if DP[idx] == -1:
        DP[idx] = (get(idx-1) + get(idx-2)) % 10007

    return DP[idx]


print(get(N))
