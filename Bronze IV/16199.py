y1, m1, d1 = map(int, input().split())
y2, m2, d2 = map(int, input().split())

age1 = 0                        # y2가 y1과 같으면 만 0세
age2 = y2 - y1 + 1              # 세는 나이
age3 = age2 - 1                 # 연 나이

if y2 > y1:                                 # y2가 y1보다 클 때
    if m2 > m1 or (m2 == m1 and d2 >= d1):  # m2가 m1보다 크거나 m2와 m1이 같으면서 d2가 d1보다 크면 만나이 = y2 - y1
        age1 = y2 - y1
    else:                                   # m2와 m1이 같으면서 d2가 d1보다 작거나, m2가 m1보다 작으면 만나이 = y2 - y1
        age1 = y2 - y1 - 1

print(age1, age2, age3, sep='\n')