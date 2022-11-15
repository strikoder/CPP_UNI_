
import numpy as np


def cross_entropy(x):
    x1 = np.array(x, dtype=float)
    ce = -np.sum(x1 * np.log2(x1))
    return ce


def cross_entropyx_y(x, y):
    x2 = np.array(x, dtype=float)
    y2 = np.array(y, dtype=float)
    ce = -np.sum(x2 * np.log2(y2 / x2))
    return ce


def Res(x, y):
    result = cross_entropy(x) + cross_entropyx_y(x, y)
    return np.round(np.sum(result), 2)


x = [float(x) for x in input().split(" ")]
y = [float(x) for x in input().split(" ")]

print(Res(x, y))

"""
import numpy as np


def cross_entropy(x, y):
    x1 = np.array(x, dtype=float)
    y1 = np.array(y, dtype=float)
    ce = -np.sum(y1 * np.log2(x1))
    return ce


def cross_entropyx_y(x, y):
    x2 = np.array(x, dtype=float)
    y2 = np.array(y, dtype=float)
    ce = 1 - np.sum(y2) * np.log(1 - np.log2(x2))
    # ce = np.sum(x2 * np.log(x2 / y2))
    return ce


def Res(x, y,n):
    result = -1/n*(cross_entropy(x, y) + cross_entropyx_y(x, y))
    return np.round(np.sum(result), 2)


x = [float(x) for x in input().split(" ")]
y = [float(x) for x in input().split(" ")]
n=len(x)

print(Res(x, y,n))
"""