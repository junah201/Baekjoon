import itertools

N = int(input())
cow = ["Bessie", "Buttercup", "Belinda",
       "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
must = []

for _ in [0]*N:
    tmp = list(input().split())
    must.append((tmp[0], tmp[5]))

nPr = itertools.permutations(sorted(cow), len(cow))
for per in list(nPr):
    is_com = True
    for cow1, cow2 in must:
        cow1_idx = per.index(cow1)
        cow2_idx = per.index(cow2)

        if abs(cow1_idx - cow2_idx) != 1:
            is_com = False
            break

    if is_com:
        print("\n".join(per))
        exit()
