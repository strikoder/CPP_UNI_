from math import exp


# my fun(var)
def f(xx, yy):
    res = 4 * pow(xx, 3) * yy
    return res


A = 0
B = 1
yy0 = 1.0

# ~20, 1600 уже не выбор
N = 32

H = (B - A) / N

X = [round(A + (H * i), 15) for i in range(N + 1)]
Y = [round(exp(pow(X[i], 4)), 15) for i in range(N + 1)]


# for α(alpha)=1/2
# метод Рунге-кутта
def Runge_Kutta(x, n, h, y0):
    y = [y0]
    for i in range(n):
        y.append(round(y[i] + (h / 2 * (f(x[i], y[i]) + f(x[i] + h, (y[i] + h * f(x[i], y[i]))))), 15))
    return y


y_runge_0_5 = Runge_Kutta(X, N, H, yy0)

delta = [round(abs(y_runge_0_5[i] - Y[i]), 15) for i in range(N + 1)]

#print("α = 0.5")
print("var=3x³y\n")
for i in range(N + 1):
    print(f"x={X[i]:0.4f}\t\t ŷ(eul) = {y_runge_0_5[i]:0.4f}\t\t y={Y[i]:0.4f}\t\t delta = {delta[i]:0.4f}")
