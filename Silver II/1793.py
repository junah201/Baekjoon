DP = [0 for i in range(251)]

while True:
    try:
        n = int(input())
        DP[0] = 1
        DP[1] = 1
        DP[2] = 3

        for i in range(3, n + 1):
            DP[i] = DP[i - 1] + 2 * DP[i - 2]

        print(DP[n])

    except:
        break
