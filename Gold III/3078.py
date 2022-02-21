#3078  좋은 친구

def main():
    N,K=map(int,input().split())
    arr=[]
    cnt=0
    for i in range(N):
        arr.append(len(input()))
    for i in range(N-K+1):
        for j in range(1,K+1):
            if(i+j==N):
                break
            if arr[i]==arr[i+j]:
                cnt+=1
    print(cnt)

if __name__ == "__main__":
    main()
