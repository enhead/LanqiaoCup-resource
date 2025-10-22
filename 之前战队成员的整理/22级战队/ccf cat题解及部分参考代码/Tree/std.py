n = int(input())
p = list(map(int , input().split()))
rt = p[0]
ls = [0 for _ in range(4000 + 10)]
rs = [0 for _ in range(4000 + 10)]

def dfs(u , x) :
    if x < u :
        if ls[u] != 0 :
            dfs(ls[u] , x)
        else :
            ls[u] = x
    else :
        if rs[u] != 0 :
            dfs(rs[u] , x)
        else :
            rs[u] = x

def dfs2(u , x , dep) :
    if x < u :
        if ls[u] != 0 :
            dfs2(ls[u] , x , dep + 1)
        else :
            print(dep + 1)
    else :
        if rs[u] != 0 :
            dfs2(rs[u] , x , dep + 1)
        else :
            print(dep + 1)

for i in range(1 , n) :
    dfs(rt , p[i])

for i in range(n , n * 2) :
    dfs2(rt , p[i] , 1)