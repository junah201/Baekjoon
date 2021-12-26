#6568  귀도 반 로썸은 크리스마스날 심심하다고 파이썬을 만들었다

n = 0

while True:
    cmd = input()
    if cmd[:3] == '000':
        n = int(cmd[3:],2)
