score = []
for _ in [0] * 6:
    score.append(int(input()))

print(sum(score) - min(score[:4]) - min(score[-2:]))
