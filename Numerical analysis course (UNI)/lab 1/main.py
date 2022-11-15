import math

# variables
n = 10
m = n * 3
a = 0
b = 2


# Lagrange's function
def lagrange(x, y, n, xx):
    l = 0.0
    for i in range(n):
        q = 1.0
        for j in range(n):
            if i != j:
                q = q * (xx - x[j]) / (x[i] - x[j])
        l = l + y[i] * q
    return l


# first & second task
x_values = []
for i in range(n + 1):
    x_values.append(round((0.2 * i), 1))

y_values = []
for i in range(n + 1):
    y_values.append(round(math.sqrt(x_values[i]) - x_values[i], 5))

# third task
lag = []
for i in range(n + 1):
    lag.append(lagrange(x_values, y_values, n + 1, x_values[i]))

# fourth task
xm_values = []
for i in range(m + 1):
    xm_values.append(round(((2 / m) * i), 5))

# fifth task
ym_values = []
lag_m = []
delta = []
for i in range(m + 1):
    ym_values.append(round(math.sqrt(xm_values[i]) - xm_values[i], 5))
    lag_m.append(lagrange(x_values, y_values, n, xm_values[i]))
    delta.append(abs(lag_m[i] - ym_values[i]))

    print(format(xm_values[i], '.5f'), format(ym_values[i], '.5f'), format(lag_m[i], '.5f'), format(delta[i], '.5f'))

print("\n\n\n\n")

# sixth task
for i in range(n + 1):
    if delta[i] <= 0.01:
        print(x_values[i])
        print(format(xm_values[i], '.5f'), format(ym_values[i], '.5f'), format(lag_m[i], '.5f'),
              format(delta[i], '.2f'))
