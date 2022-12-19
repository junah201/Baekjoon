from ast import Or
import sys

N, M = map(int, sys.stdin.readline().split())

idx = 1
origin_mons = {}

for i in range(N):
    inp = sys.stdin.readline().strip()
    if origin_mons.get(inp) == None:
        origin_mons[inp] = idx
        idx += 1

reversed_mons = {v: k for k, v in origin_mons.items()}


for i in range(M):
    inp = sys.stdin.readline().strip()
    if origin_mons.get(inp) != None:
        print(origin_mons[inp])
    else:
        print(reversed_mons[int(inp)])
