import sys
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
for i in query:
    val = dict([j.split(":") for j in i.replace("=", ":")[1:-1].split(",")])
    val = dict([[j, int(val[j])] for j in val])
    
    start = "in"
    flag = 0

    while(True):

        if(start == 'A'):
            flag = 1
            break

        if(start == 'R'):
            flag = 0
            break

        l = mp[start]
        for j in l:
            if(j.isalpha()):
                start = j
                break
            else:
                temp = j.split(":")[0]
                next = j.split(":")[1]

                if(temp[1] == "<" and val[temp[0]] < int(temp[2:])):
                    start = next
                    break
                elif(temp[1] == ">" and val[temp[0]] > int(temp[2:])):
                    start = next
                    break

    if(flag == 1):
        ans += sum([val[j] for j in val])
                

print(ans)
