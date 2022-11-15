import math

n = 10
m = n * 3
a = 0
b = 2


def newtonfun(x, y, n, xx):
    l = y[0]
    for i in range(n):
        f = 0.0
        for j in range(i + 1):
            d = 1.0
            for z in range(i + 1):
                if z != j:
                    d *= (x[j] - x[z])
            f += y[j] / d
        for k in range(i):
            f *= (xx - x[k])
        l += f
    return l


# first & second task
x_values = []
for i in range(n + 1):
    x_values.append(round((0.2 * i), 1))

y_values = []
for i in range(n + 1):
    y_values.append(round(math.sqrt(x_values[i]) - x_values[i], 5))

# third task
newton = []
for i in range(n + 1):
    newton.append(newtonfun(x_values, y_values, n + 1, x_values[i]))

# fourth task
xm_values = []
for i in range(m + 1):
    xm_values.append(round(((2 / m) * i), 5))

# fifth task
ym_values = []
newton_m = []
delta = []
for i in range(m + 1):
    ym_values.append(round(math.sqrt(xm_values[i]) - xm_values[i], 5))
    newton_m.append(newtonfun(x_values, y_values, n, xm_values[i]))
    delta.append(abs(newton_m[i] - ym_values[i]))

    print(format(xm_values[i], '.5f'), format(ym_values[i], '.5f'), format(newton_m[i], '.5f'), format(delta[i], '.5f'))

print("\n\n\n\n")


# sixth task
for i in range(n + 1):
    if delta[i] <= 0.1:
        print(format(xm_values[i], '.5f'), format(ym_values[i], '.5f'), format(newton_m[i], '.5f'),
              format(delta[i], '.5f'))
