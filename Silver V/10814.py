#10814  나이순 정렬

N=int(input())

age=[]
name=[]

for i in range(N):
    a,b = input().split()
    age.append(int(a))
    name.append(b)


for i in range(N):
    for j in range(N-1):
        if age[j] > age[j+1]:
            age[j],age[j+1]=age[j+1],age[j]
            name[j],name[j+1]=name[j+1],name[j]

for i in range(N):
    print(f"{age[i]} {name[i]}")