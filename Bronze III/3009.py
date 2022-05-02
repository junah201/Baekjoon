# 3009 네 번째 점

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())

ra = 0
if a1 == a2:
    ra = a3
elif a2 == a3:
    ra = a1
else:
    ra = a2
    
rb = 0
if b1 == b2:
    rb = b3
elif b2 == b3:
    rb = b1
else:
    rb = b2
    
print(ra, rb)