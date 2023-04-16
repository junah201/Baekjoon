import sys
import math

T = int(sys.stdin.readline())


def parsing_equation(row_equation: list) -> dict:
    equation = {
        'x': 0,
        'y': 0,
        'num': 0,
    }

    is_before_equal_sign = True
    is_minus = False

    for i in row_equation:
        if i == "=":
            is_before_equal_sign = False
        elif i == "+":
            pass
        elif i == "-":
            is_minus = True
        else:
            if (i[-1] == "x" or i[-1] == "y"):
                if len(i) == 1:
                    tmp = 1
                elif len(i) == 2 and i[0] == '-':
                    tmp = -1
                else:
                    tmp = int(i[:-1])

                if is_minus:
                    tmp *= -1
                    is_minus = False

                if not is_before_equal_sign:
                    tmp = -1 * tmp

                equation[i[-1]] += int(tmp)
            else:
                tmp = int(i)

                if is_minus:
                    tmp *= -1
                    is_minus = False

                if not is_before_equal_sign:
                    tmp = -1 * tmp

                equation["num"] -= int(tmp)

    gcd = math.gcd(math.gcd(equation['x'], equation['y']), equation['num'])

    return equation


def get_fraction(a: int, b: int):
    """return b/a
    """
    if (b == 0):
        return "0"

    if (a < 0):
        a *= -1
        b *= -1

    gcd = math.gcd(a, b)

    if a // gcd == 1:
        return f"{b // gcd}"

    return f"{b // gcd}/{a // gcd}"


def solve():
    equation1 = parsing_equation(sys.stdin.readline().split())
    equation2 = parsing_equation(sys.stdin.readline().split())
    sys.stdin.readline()

    x = "don't know"
    y = "don't know"

    if (equation1['x'] == 0 and equation1['y'] == 0 and equation1['num'] != 0):
        print(x)
        print(y)
        print()
        return

    if (equation2['x'] == 0 and equation2['y'] == 0 and equation2['num'] != 0):
        print(x)
        print(y)
        print()
        return

    """
    ax + dy = c
    dx + ey = f

    [a b] [x]   [c]
    [d e] [y] = [f]

    D = ab - de

    D가 0일 경우 => 해가 없음
    D가 0이 아니지만, 

    ab - de != 0 이여야 역행렬이 있음
    """

    a, b = equation1['x'], equation1['y']
    c, d = equation2['x'], equation2['y']
    b1, b2 = equation1['num'], equation2['num']

    D = a*d - b*c

    if D == 0:
        x = "don't know"
        y = "don't know"

        if equation1['x'] == 0 and equation1['y'] != 0 and equation2['x'] == 0 and equation2['y'] != 0:
            if get_fraction(equation1['y'], equation1['num']) == get_fraction(equation2['y'], equation2['num']):
                y = get_fraction(equation2['y'], equation2['num'])

        if (equation1['x'] != 0 and equation1['y'] == 0 and equation2['x'] != 0 and equation2['y'] == 0):
            if get_fraction(equation1['x'], equation1['num']) == get_fraction(equation2['x'], equation2['num']):
                x = get_fraction(equation1['x'], equation1['num'])

        if (equation1['x'] == 0 and equation1['y'] != 0 and not (equation2['x'] == 0 and equation2['y'] != 0)):
            y = get_fraction(equation1['y'], equation1['num'])
        if (equation1['x'] != 0 and equation1['y'] == 0 and not (equation2['x'] != 0 and equation2['y'] == 0)):
            x = get_fraction(equation1['x'], equation1['num'])

        if (equation2['x'] == 0 and equation2['y'] != 0 and not (equation1['x'] == 0 and equation1['y'] != 0)):
            y = get_fraction(equation2['y'], equation2['num'])
        if (equation2['x'] != 0 and equation2['y'] == 0 and not (equation1['x'] != 0 and equation1['y'] == 0)):
            x = get_fraction(equation2['x'], equation2['num'])

    else:
        if get_fraction(b, a) != get_fraction(d, c):
            # 두 방정식이 서로 다른 기울기를 가질 경우
            x = get_fraction(D, (d*b1 - b*b2))
            y = get_fraction(D, (-c*b1 + a*b2))

    print(x)
    print(y)
    print()


for _ in range(T):
    solve()
