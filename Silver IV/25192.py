import itertools

N = int(input())
A = []

for _ in range(N):
    A.append(input())

result = [len(set(group))
          for k, group in itertools.groupby(A, lambda x: x != "ENTER") if k]

print(sum(result))
