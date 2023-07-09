import sys
input = sys.stdin.readline

N, M = map(int, input().split())

words = {}

for _ in range(N):
    S = input().rstrip()

    if len(S) < M:
        continue

    words[S] = words.get(S, 0) + 1

words = sorted(words.items(), key=lambda x: (-x[1], -len(x[0]), x[0]))

for word in words:
    print(word[0])
