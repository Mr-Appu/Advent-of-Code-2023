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

ans = 0
for [(x1, y1, z1), (vx1, vy1, vz1)] in d:
    for [(x2, y2, z2), (vx2, vy2, vz2)] in d:        
        #  Line 1
        m1 = vy1/vx1
        c1 = y1 - m1*x1
    	# Line 2
        m2 = vy2/vx2
        c2 = y2 - m2*x2
        # Parallel
        if m1 == m2:
            continue
        x = (c2 - c1)/(m1 - m2)
        y = m1*x + c1
        # Past
        delta_x1 = (x - x1) * vx1 
        delta_y1 = (y - y1) * vy1
        delta_x2 = (x - x2) * vx2
        delta_y2 = (y - y2) * vy2
        if(delta_x1 < 0 or delta_x2 < 0 or delta_y1 < 0 or delta_y2 < 0):
            continue
        if x >= 200000000000000 and x <= 400000000000000 and y >= 200000000000000 and y <= 400000000000000:
            ans += 1
        
print(ans/2)
