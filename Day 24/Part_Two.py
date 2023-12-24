import sys
import math
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stderr = open("output.txt", "w")

with open("input.txt", "r") as f:
    data = f.readlines()

d = []
for i in data:
    i = i.split(" @ ")
    i = [tuple(map(int, j.split(", "))) for j in i]
    d.append(i)

# https://www.youtube.com/watch?v=guOyA7Ijqgk , 🙇🙇🙇

import sympy

xr, yr, zr, vxr, vyr, vzr = sympy.symbols("xr, yr, zr, vxr, vyr, vzr")
equations = []

for i, [(sx, sy, sz), (vx, vy, vz)] in enumerate(d):
    equations.append((xr - sx) * (vy - vyr) - (yr - sy) * (vx - vxr))
    equations.append((yr - sy) * (vz - vzr) - (zr - sz) * (vy - vyr))

answer = sympy.solve(equations)[0]
print(answer)
print(answer[xr] + answer[yr] + answer[zr])
