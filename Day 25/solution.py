import sys
import math
import networkx
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stderr = open("output.txt", "w")

with open("input.txt", "r") as f:
    data = f.readlines()

# https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.connectivity.cuts.minimum_edge_cut.html
# 🙇🙇🙇

graph = networkx.Graph()

for i in data:
    node = i.split()[0][:-1]
    adj_nodes = i.split()[1:]
    for adj_node in adj_nodes:
        graph.add_edge(node, adj_node)

remove = networkx.minimum_edge_cut(graph)
graph.remove_edges_from(remove)

ans = 1

for i in networkx.connected_components(graph):
    ans *= len(i)

print(ans)
