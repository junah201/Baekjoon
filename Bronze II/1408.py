h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))

rh = h2 - h1
rm = m2 - m1
rs = s2 - s1

while rs < 0:
    rs += 60
    rm -= 1

while rs >= 60:
    rs -= 60
    rm += 1

while rm < 0:
    rm += 60
    rh -= 1

while rm >= 60:
    rm -= 60
    rh += 1

while rh < 0:
    rh += 24

while rh >= 24:
    rm -= 24

print("%02d:%02d:%02d" % (rh, rm, rs))