import sys
ssr = sys.stdin.readline

N, M = map(int, ssr().split())
graph = [list(ssr().split()[0]) for _ in range(N)]

height = 3001
for j in range(M):
    sharp_min = 3001
    x_max = 0
    for i in range(N):
        if graph[i][j] == '#':
            sharp_min = min(sharp_min, i)
        elif graph[i][j] == 'X':
            x_max = max(x_max, i)
    height = min(sharp_min - x_max - 1, height)

new_graph = [['#' if graph[i][j] ==
              '#' else '.' for j in range(M)] for i in range(N)]

for i in range(N):
    for j in range(M):
        if graph[i][j] == 'X':
            new_graph[i + height][j] = graph[i][j]

for i in new_graph:
    print("".join(i))
