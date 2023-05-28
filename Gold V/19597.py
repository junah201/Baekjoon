T = int(input())

N = 0
inp = []
tmp = []
is_end = False


def rever(string, reverse):
    if reverse:
        return string[::-1]
    else:
        return string


def dfs(idx):
    global is_end
    if is_end:
        return

    if idx == N:
        print(''.join(map(str, tmp)))
        is_end = True
        return

    tmp[idx] = 0
    if idx == 0 or rever(inp[idx - 1], tmp[idx - 1]) <= rever(inp[idx], tmp[idx]):
        dfs(idx + 1)

    tmp[idx] = 1
    if idx == 0 or rever(inp[idx - 1], tmp[idx - 1]) <= rever(inp[idx], tmp[idx]):
        dfs(idx + 1)


def solve():
    global inp
    global N
    global tmp
    global is_end

    N = int(input())
    tmp = [0 for _ in range(N)]

    inp = []
    for _ in range(N):
        inp.append(input())
    is_end = False

    dfs(0)


for _ in range(T):
    solve()
