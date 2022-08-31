N = int(input())
M = int(input())

graph = [[] for _ in [0]*(N+1)]
check = [False for _ in [0]*(N+1)]

for _ in [0] * M:
    start, end = map(int, input().split())
    graph[start].append(end)
    graph[end].append(start)


def dfs(idx: int):
    if check[idx]:
        return
    check[idx] = True
    for next in graph[idx]:
        dfs(next)


dfs(1)

print(sum(check) - 1)
