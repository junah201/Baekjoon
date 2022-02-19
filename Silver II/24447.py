# 24447  알고리즘 수업 - 너비 우선 탐색 4
# https://www.acmicpc.net/source/39318809

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
T = [0 for _ in range(N+1)]
D = [0 for _ in range(N+1)]

T[R] = 1
D[R] = 1

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N+1):
    graph[i].sort()

queue = []
queue.append(R)

cnt = 1

while queue:
    cur = queue.pop(0)

    for i in graph[cur]:
        if T[i] == 0:
            cnt += 1
            T[i] = cnt
            queue.append(i)
            D[i] = D[cur] + 1

sum = 0
for i in range(1, N+1):
    sum += T[i] * (D[i]-1)

print(sum)