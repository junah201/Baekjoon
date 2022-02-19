def solve():
    N, M = map(int, input().split())
    queue = list(map(int, input().split()))
    result = queue[M]
    cnt = 1
    while queue:
        ans = max(queue)
        cur = queue.pop(0)
        print(cur, "==")
        if cur == ans:
            if cur == result:
                print(cnt)
                return
            cnt += 1
        else:
            queue.append(cur)

for _ in range(int(input())):
    solve()
