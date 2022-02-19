# 24446  알고리즘 수업 - 너비 우선 탐색 3
# https://www.acmicpc.net/source/39318403

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N+1):
    graph[i].sort(reverse=True)

queue = []
queue.append(R)
visited[R] = 1

while queue:
    cur = queue.pop(0)

    for i in graph[cur]:
        if visited[i] == 0:
            visited[i] = visited[cur] + 1
            queue.append(i)

for i in visited[1:]:
    print(i-1)