n = int(input())
a, b = 1, 1
for i in range(1, n+1):
    t = a
    a = b
    b = (t + b) % 1000000007
print((b * b)%1000000007)