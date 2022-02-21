#2492  보석

def main():
    #입력
    N,M,T,K=map(int,input().split())
    map = [[0 for col in range(1000001)] for row in range(1000001)]
    for i in range(T):
        x,y = map(int,input().split())
        map[y][x] += 1
    #시작값
    sum = 0
    for x in range(K+1):
        for y in range(K+1):
            sum+=map[y][x]
    max = sum
    max_x = 0
    max_y = 0
    #슬라이싱
    for x in range(0,N-K):
        for y in range(0,M-K):
            sum-=

if __name__ == "__main__":
    main()
