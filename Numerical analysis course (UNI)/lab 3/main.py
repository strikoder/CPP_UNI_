import scipy.integrate as integrate
from math import sqrt

N = 16
a = 0
b = 1


def f(x):
    return sqrt(x)



I = integrate.quad(lambda x: sqrt(x), a, b)

def left_integral(f, x2, x1, n):
    m = (x2 - x1) / n
    result = 0
    for i in range(N - 1):
        result += f(x1 + (i * m)) * m
    return result
def right_integral(f, x2, x1, n):
    m = (x2 - x1) / n
    result = 0
    for i in range(1, N):
        result += f(x1 + (i * m)) * m
    return result
def trapezoid(f, x2, x1, n):
    m = (x2 - x1) / n
    result = 0
    for i in range(N):
        first_val = f(x1 + i * m)
        second_val = f(x1 + (i + 1) * m)
        result += ((first_val + second_val) / 2) * m
    return result
def simpson(f, x2, x1, n):
    m = (x2 - x1) / n
    result = 0
    for i in range(N):
        first_val = f(x1 + i * m)
        second_val = 4 * f(x1 + (i + 1 / 2) * m)
        third_val = f(x1 + (i + 1) * m)
        result += ((first_val + second_val + third_val) / 6) * m
    return result


print('f(x)=√x')

print("\nTask №2")
number = N
print(
    f"N= {N}\t I= {I[0]:.4f}\tI(N,L) = {left_integral(f, b, a, N):.4f}\t     I(N,R)={right_integral(f, b, a, N):.4f}\t    I(N,T) = {trapezoid(f, b, a, N):.4f}\t     I(N,S) = {simpson(f, b, a, N):.4f}")
N = 2 * number
print(
    f"N= {N}\t I= {I[0]:.4f}\tI(2N,L) = {left_integral(f, b, a, N):.4f}\t I(2N,R)={right_integral(f, b, a, N):.4f}\t    I(2N,T) = {trapezoid(f, b, a, N):.4f}\t I(2N,S) = {simpson(f, b, a, N):.4f}")
N = 5 * number
print(
    f"N= {N}\t I= {I[0]:.4f}\tI(5N,L) = {left_integral(f, b, a, N):.4f}\t I(5N,R)={right_integral(f, b, a, N):.4f}\t    I(5N,T) = {trapezoid(f, b, a, N):.4f}\t I(5N,S) = {simpson(f, b, a, N):.4f}")
N = 10 * number
print(
    f"N= {N}\t I= {I[0]:.4f}\tI(10N,L) = {left_integral(f, b, a, N):.4f}\t I(10N,R)={right_integral(f, b, a, N):.4f}\tI(10N,T) = {trapezoid(f, b, a, N):.4f}\t I(10N,S) = {simpson(f, b, a, N):.4f}")

print("===================================")
print("Task №3")
for N in range(1600, 1604):
    print(
        f"N= {N}\t I= {I[0]:.4f}\t I(N,L) = {left_integral(f, b, a, N):.4f}\t {abs(I[0] - left_integral(f, b, a, N)):.4f}")

print("===================================")
print("Task №4")
for N in range(550, 554):
    print(
        f"N= {N}\t I= {I[0]:.4f}\tI(N,R) = {right_integral(f, b, a, N):.4f}\t {abs(I[0] - right_integral(f, b, a, N)):.4f}")

print("===================================")
print("Task №5")
for N in range(36, 40):
    print(f"N= {N}\t I= {I[0]:.4f}\tI(N,T) = {trapezoid(f, b, a, N):.4f}\t {abs(I[0] - trapezoid(f, b, a, N)):.4f}")

print("===================================")
print("Task №6")
for N in range(10, 17, 2):
    print(f"N= {N}\t I= {I[0]:.4f}\tI(N,S) = {simpson(f, b, a, N):.4f}\t {abs(I[0] - simpson(f, b, a, N)):.4f}")
