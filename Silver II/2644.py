N = int(input())
start, end = map(int, input().split())
T = int(input())
users = [[] for _ in range(N + 1)]
check = [False for _ in range(N + 1)]
for _ in [0]*T:
    S, E = map(int, input().split())
    users[S].append(E)
    users[E].append(S)


def DFS(idx, stack):
    global users
    global check

    if check[idx]:
        return

    check[idx] = 1

    if idx == end:
        print(stack)
        exit()

    for next in users[idx]:
        DFS(next, stack + 1)


DFS(start, 0)
print(-1)
