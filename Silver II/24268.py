#24268  2022는 무엇이 특별할까?

import string
from itertools import permutations

#진법 전환
def convert(num, base) :
    tmp = string.digits+string.ascii_lowercase
    q, r = divmod(num, base)
    if q == 0 :
        return tmp[r] 
    else :
        return convert(q, base) + tmp[r]

def main():
    N,d = map(int,input().split())
    #0123...인 문자열 생성
    temp = ''
    for i in range(0,d):
        temp += str(i)
    #순열 생성
    per = [''.join(p) for p in permutations(temp)]
    #순열에서 입력 값보다 큰 순열 찾기
    for i in per:
        if int(i,d) > N:
            if i[0]== '0':
                continue
            else:
                print(int(i,d))
                return
    print(-1)
    return

main()