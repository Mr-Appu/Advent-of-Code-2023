import sys
import math
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stderr = open("output.txt", "w")

with open("input.txt", "r") as f:
    data = f.read().split("\n\n")
    
    compute = data[0].split()
    query = data[1].split()

mp = {}
for i in compute:
    mp[i.split("{")[0]] = i.split("{")[1][:-1].split(',')

ans = 0
start = "in"
ranges = {"x":[1, 4000], "m":[1, 4000], "a":[1, 4000], "s":[1, 4000]}

def dfs(start, ranges):    
    global ans

    if(start == 'A'):
        ans += math.prod([ranges[j][1] - ranges[j][0] + 1 for j in ranges])
        return

    if(start == 'R'):
        return

    l = mp[start]
    for j in l:
        if(j.isalpha()):
            dfs(j, ranges)
        else:
            temp = j.split(":")[0]
            next = j.split(":")[1]

            if(temp[1] == "<"):
                c = ranges.copy()
                c[temp[0]] = [c[temp[0]][0], int(temp[2:])-1]
                ranges[temp[0]] = [int(temp[2:]), ranges[temp[0]][1]]
                dfs(next, c)
            elif(temp[1] == ">"):
                c = ranges.copy()
                c[temp[0]] = [int(temp[2:])+1, c[temp[0]][1]] 
                ranges[temp[0]] = [ranges[temp[0]][0], int(temp[2:])]
                dfs(next, c)

dfs(start, ranges)
print(ans)
