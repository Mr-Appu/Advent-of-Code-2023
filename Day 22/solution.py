import sys
import math
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stderr = open("output.txt", "w")

with open("input.txt", "r") as f:
    data = f.readlines()

arr = []

for i in data:
    i = i.replace("\n", "")
    i = i.split("~")
    f = list(map(int, i[0].split(",")))
    s = list(map(int, i[1].split(",")))
    arr.append((f, s))

# Sort 
arr.sort(key = lambda x : x[0][2])

# Height Map
map_z = {} #(x, y) -> (max z, index)

# Support Graph
graph = [[] for i in range(len(arr))]

for index, point in enumerate(arr):
    x1, y1, z1 = point[0]
    x2, y2, z2 = point[1]
    
    max_z = 0
    for x in range(x1, x2+1):
        for y in range(y1, y2+1):
            max_z = max(max_z, map_z.get((x, y), (0, -1))[0])
    
    height = z2 - z1 + 1

    for x in range(x1, x2+1):
        for y in range(y1, y2+1):
            old_h = map_z.get((x, y), (0,-1))[0]
            old_i = map_z.get((x, y), (0,-1))[1]
            if(old_h == max_z and old_i != -1):
                graph[old_i].append(index)
            map_z[(x, y)] = (height + max_z, index)

graph = [list(set(i)) for i in graph]


# PART 1

inverse_graph = [[] for _ in range(len(graph))]
for index, lst in enumerate(graph):
    for node in lst:
        inverse_graph[node].append(index)

inverse_graph = [list(set(i)) for i in inverse_graph]

unsafe = set()

for i in inverse_graph:
    if(len(i) == 1):
        unsafe.add(i[0])

print(len(graph) - len(unsafe))

# PART 2

in_degree = [0 for _ in range(len(graph))]
for index, nodes in enumerate(inverse_graph):
    in_degree[index] += len(nodes)

def topo(graph, start, in_degree):
    ans = 0
    q = [start]
    while(q):
        ans += 1
        i = q.pop(0) 
        for node in graph[i]:
            in_degree[node] -= 1
            if(in_degree[node] == 0):
                q.append(node)
    return ans-1

part_2 = 0
for i in unsafe:
    in_degree_copy = in_degree.copy()
    part_2 += topo(graph, i, in_degree_copy)

print(part_2)
