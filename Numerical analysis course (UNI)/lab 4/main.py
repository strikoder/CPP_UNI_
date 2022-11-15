import numpy as np
from math import exp
#№4

# Интеграл 1-ого степень
def integ(xx, yy):
    res = 4 * pow(xx, 3) * yy
    return res


A = 0
B = 1

# При N = 760 У нас выполняется условие
N = 4000
H = (B - A) / N

YO = 1.0

X = [round(A + (H * i), 4) for i in range(N)]
Y = [round(exp(pow(X[i], 4)), 4) for i in range(N)]

#Euler
def equation(x, n, h, y0):
    list = [y0]
    for i in range(1, n + 1):
        list.append(round(list[i - 1] + h * integ(x[i - 1], list[i - 1]), 4))
    return list


y_euler = equation(X, N, H, YO)
delta = [round(abs(y_euler[i] - Y[i]), 2) for i in range(N)]

for i in range(N):
    print(f"x={X[i]:.4f}\t ȳ(eul) = {y_euler[i]:.4f}\t y={Y[i]:.4f}\t delta = {delta[i]:.4f}")

"""

import numpy as np
from math import exp

A = 0
B = 1
YO = 1.0
#10000
N =200
H = (B - A) / N
X = [round(A + (H * i), 4) for i in range(N)]
Y = [round(exp(pow(X[i], 4)), 4) for i in range(N)]


def equation(x, n, h, y0):
    y = [y0]
    for i in range(1, n + 1):
        y.append(round(y[i - 1] + h * f(x[i - 1], y[i - 1]), 4))
    return y


##for the first derivates of y
def f(xx, yy):
    res = 2 * xx * yy
    return res


y_euler = equation(X, N, H, YO)
delta = [round(abs(y_euler[i] - Y[i]), 2) for i in range(N)]

for i in range(N):
    print(f"x={X[i]:.4f}\t y_euler = {y_euler[i]:.4f}\t y={Y[i]:.4f}\t delta = {delta[i]:.4f}")

"""
