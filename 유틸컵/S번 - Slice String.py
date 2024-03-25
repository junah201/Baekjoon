import sys
input = sys.stdin.readline

문자구분자_개수 = int(input())
문자구분자 = list(map(str, input().split()))

숫자구분자_개수 = int(input())
숫자구분자 = list(map(str, input().split()))

병합자_개수 = int(input())
병합자 = list(map(str, input().split()))

기준문자열_길이 = int(input())
기준문자열 = input().rstrip()

구분자 = set(문자구분자 + 숫자구분자 + [" "])
for 병 in 병합자:
    if 병 in 구분자:
        구분자.remove(병)

정답 = ""

for 문 in list(기준문자열):
    if 문 in 구분자:
        정답 += " "
    else:
        정답 += 문


정답 = 정답.split()
for 정 in 정답:
    print(정)
