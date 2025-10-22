import sys
 
n = int(input())
l = list(map(int,input().split()))
c = list(map(int,input().split()))
 
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a
 
a = {0:0}
b = [0]
 
for i in range(n):
    for p in b:
        d = gcd(p, l[i])
        cost = a[p] + c[i]
        if d not in a:
            a[d] = cost
            b.append(d)
        elif a[d] > cost: a[d] = cost
 
if 1 not in a: a[1] = -1
print(a[1])