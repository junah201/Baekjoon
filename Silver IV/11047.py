N, M = map(int, input().split())
coins = []
for _ in [0] * N:
    coins.append(int(input()))

ans = 0

for coin in reversed(coins):
    if coin > M:
        continue

    ans += M // coin
    M %= coin

print(ans)
