from math import *

def f(x, y):
    return float(y**2 - 2*x*y - 6*y +2*x**2+15+cos(10*x))


def dfx(x, y):
    return float(-2*y + 4*x - 10 * sin(10*x))


def dfy(x, y):
    return float(2*y - 2*x -6)


hessian = [[lambda x: 2/(2*(4-100*cos(10*x)) - 4), lambda x: 2/(2*(4-100*cos(10*x)) - 4)],
           [lambda x: 2/(2*(4-100*cos(10*x)) - 4), lambda x: (4-100*cos(10*x))/(2*(4-100*cos(10*x)) - 4)]]

x0 = y0 = 1.0
lbd = 0.1
new_x = new_y = 1.0

while True:
    x0 = new_x
    y0 = new_y

    hlmx = (hessian[0][0](x0) * dfx(x0,y0) + hessian[0][1](x0) * dfy(x0,y0)) + lbd * dfx(x0,y0)
    hlmy = (hessian[1][0](x0) * dfx(x0,y0) + hessian[1][1](x0) * dfy(x0,y0)) + lbd * dfy(x0,y0)

    new_x = x0 - hlmx
    new_y = y0 - hlmy

    skip = False
    if f(new_x, new_y) < f(x0, y0):
        lbd /= 2
    else:
        lbd *= 2
        skip = True

    if not skip and new_x-x0<0.00001 and new_y-y0<0.00001:
        print("X = {0}, Y = {1}".format(new_x, new_y))
        print(f(new_x, new_y))
        break


