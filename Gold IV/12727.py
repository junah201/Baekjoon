import sys
from decimal import Decimal

T = int(sys.stdin.readline())

for i in range(T):
    N = int(sys.stdin.readline())

    A = Decimal(
        '3') + Decimal('2.236067977499789696409173668731276235440618359611525724270897')
    B = Decimal('1')

    for _ in range(N):
        B = B * A

    C = int(B) % 1000

    print(f"Case #{i + 1}: {C:03d}")
