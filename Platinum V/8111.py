def bfs(N : int):
    queue = [["1",1,0]]
    while(queue):
        cur = queue.pop(0)
        # print(cur, int(cur[0]) % N)
        if cur[1] == 0:
            return cur[0]
        if cur[2] >= 100:
            return "BRAK";
        queue.append([
            cur[0] + "1",
            (cur[1] * 10 + 1) % N,
            cur[2] + 1
            ])
        queue.append([
            cur[0] + "0",
            (cur[1] * 10 + 0) % N,
            cur[2] + 1
            ])

for N in [*open(0)][1:]:
    print(bfs(int(N)))