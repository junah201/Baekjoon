N = int(input())

가지 = list(input().split())

M, K = map(int, input().split())

for _ in range(M):
    new_가지 = list(map(int, input().split()))

    for i in new_가지:
        if 가지[i - 1] == 'P':
            break
    else:
        print("W")
        exit()

print("P")
