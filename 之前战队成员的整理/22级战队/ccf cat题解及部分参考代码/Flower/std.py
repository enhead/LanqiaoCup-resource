t = [0 for _ in range(100000 + 10)]
v = [0 for _ in range(100000 + 10)]
p = [0 for _ in range(100000 + 10)]
heap = [0 for _ in range(100000 + 10)]
siz = 0
def down(x) :
    global siz
    t = x
    if 2 * x <= siz and heap[t] > heap[2 * x] :
        t = 2 * x
    if 2 * x + 1 <= siz and heap[t] > heap[2 * x + 1] :
        t = 2 * x + 1
    if t != x :
        tmp = heap[x]
        heap[x] = heap[t]
        heap[t] = tmp
        down(t)

def up(u) :
    while u // 2 > 0 and heap[u // 2] > heap[u] :
        tmp = heap[u // 2]
        heap[u // 2] = heap[u]
        heap[u] = tmp
        u //= 2

def pop() :
    global siz
    x = heap[1]
    heap[1] = heap[siz]
    siz -= 1
    down(1)
    return x

n , k = map(int , input().split())
tt = list(map(int , input().split()))
vv = list(map(int , input().split()))
for i in range(n) :
    t[i + 1] = tt[i]
    v[i + 1] = vv[i]
    p[tt[i]] = vv[i]

for i in range(100000 , 0 , -1) :
    if p[i] == 0 :
        continue
    siz += 1
    heap[siz] = p[i]
    up(siz)
    if siz > k :
        pop()

s = 0
while siz > 0 :
    s += pop()

print(s)