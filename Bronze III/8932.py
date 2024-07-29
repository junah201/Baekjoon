from decimal import Decimal
import sys

input = sys.stdin.readline


def solve():
    a, b, c, d, e, f, g = map(int, input().split())

    ans = 0
    ans += int(Decimal(9.23076 * ((26.7 - a) ** 1.835)))  # 트
    ans += int(Decimal(1.84523 * ((b - 75) ** 1.348)))  # 필
    ans += int(Decimal(56.0211 * ((c - 1.5) ** 1.05)))  # 필
    ans += int(Decimal(4.99087 * ((42.5 - d) ** 1.81)))  # 트
    ans += int(Decimal(0.188807 * ((e - 210) ** 1.41)))  # 필
    ans += int(Decimal(15.9803 * ((f - 3.8) ** 1.04)))  # 필
    ans += int(Decimal(0.11193 * ((254 - g) ** 1.88)))  # 트

    print(ans)


T = int(input())

for _ in range(T):
    solve()
