# https://www.youtube.com/watch?v=zw7WwUZfYrs

import sys
import math
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stderr = open("output.txt", "w")

with open("input.txt", "r") as f:
    data = f.readlines()

graph = {}
flip_flop = {}
conj = {}

rx_conj = ""
rx_conj_presses = {}

for line in data:
    src, dest = line.replace("\n", "").split(" -> ")
    dest = dest.split(", ")

    if src == "broadcaster":
        graph[src] = dest
    else:
        graph[src[1:]] = dest
    
    if src[0] == "%":
        flip_flop[src[1:]] = False

    if src[0] == "&":
        conj[src[1:]] = {} # {input : pulse}

    if "rx" in dest:
        rx_conj = src[1:]
    
for src, dests in graph.items():
    for dest in dests:
        if dest in conj:
            conj[dest][src] = 0

low = 0
high = 0
press = 0

def button():
    global low, high, press

    press += 1
    low += 1

    q = []
    for dest in graph["broadcaster"]:
        q.append((0, "broadcaster", dest))
        low += 1

    while q:
        pulse, src, dest = q.pop(0)

        new_pulse = 0

        if dest in flip_flop:
            if pulse == 1:
                continue
            flip_flop[dest] = not flip_flop[dest]
            if flip_flop[dest]:
                new_pulse = 1

        if dest in conj:
            conj[dest][src] = pulse
            if any(n == 0 for n in conj[dest].values()):
                new_pulse = 1

        for next in graph.get(dest, []):
            if(new_pulse):
                high += 1
            else:
                low += 1

            q.append((new_pulse, dest, next)) 

        for dest, pulse in conj[rx_conj].items():
            if(pulse == 1 and dest not in rx_conj_presses):
                rx_conj_presses[dest] = press
               
while len(rx_conj_presses) < 4:
    button()

print(math.prod(rx_conj_presses.values()))
