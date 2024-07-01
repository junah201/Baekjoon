import sys
input = sys.stdin.readline

n = int(input())
논재 = [
    input().strip() for _ in range(n)
]
m = int(input())
결론 = [
    input().strip() for _ in range(m)
]

graph = [
    list() for _ in range(26)
]
visited = [
    False for _ in range(26)
]
ans = False


def dfs(now: int, aim: int):
    global visited
    global ans
    visited[now] = True

    if ans:
        return

    if now == aim:
        ans = True
        return

    for next in graph[now]:
        if visited[next]:
            continue

        visited[next] = True
        dfs(next, aim)


for s in 논재:
    first = ord(s[0]) - ord('a')
    second = ord(s[-1]) - ord('a')

    graph[first].append(second)


for s in 결론:
    first = ord(s[0]) - ord('a')
    second = ord(s[-1]) - ord('a')

    # reset visited
    visited = [
        False for _ in range(26)
    ]
    ans = False

    dfs(first, second)

    if ans:
        print('T')
    else:
        print('F')
