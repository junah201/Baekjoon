#12605  단어순서 뒤집기

N = int(input())
for i in range(N):
    Arr = input().split()
    msg = ""
    for j in range(len(Arr)-1,-1,-1):
        msg += Arr[j] + " "
    print(f"Case #{i+1}: {msg[:-1]}")