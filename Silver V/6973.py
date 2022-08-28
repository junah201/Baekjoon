import sys

for _ in range(int(sys.stdin.readline())):
    번호 = 1
    사전 = {}

    while(1):
        입력값 = list(sys.stdin.readline().split())
        if not 입력값:
            break
        결과값 = []

        for 입력 in 입력값:
            if 사전.get(입력) != None:
                결과값.append(사전[입력])
            else:
                결과값.append(입력)
                사전[입력] = str(번호)
                번호 += 1
        print(" ".join(결과값))
    print()
