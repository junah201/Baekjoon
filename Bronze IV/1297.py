# 1297  TV 크기
# https://www.acmicpc.net/source/38246488

D, H, W = map(int, input().split())

ans1 = int((H*D)/((H**2)+(W**2)) ** 0.5)
ans2 = int((W*D)/((H**2)+(W**2)) ** 0.5)

print(ans1, ans2)