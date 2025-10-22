import heapq
import sys

MAXN = 1005
INF = 10 ** 18


def dijkstra(s):
    pq = []
    dis = [INF] * MAXN
    vis = [False] * MAXN
    dis[s] = 0
    heapq.heappush(pq, (0, s))

    while pq:
        d, u = heapq.heappop(pq)
        if vis[u]:
            continue
        vis[u] = True
        for v, w in graph[u]:
            new_dis = dis[u] + w
            if new_dis < dis[v]:
                dis[v] = new_dis
                heapq.heappush(pq, (dis[v], v))

    return dis


def dfs(u, parent, last):
    if vis[u]:
        return
    vis[u] = True
    for v, w in adj[u]:
        if v == parent:
            continue
        if last != -1 and w % last == 0:
            graph[parent].append((v, w))
        dfs(v, u, w)


def add_new_edge(n):
    for i in range(1, n + 1):
        for next_u, len1 in adj[i]:
            for next_next_u, len2 in adj[next_u]:
                pa = i
                v = next_next_u
                if len2 % len1 == 0 and pa != v:
                    graph[pa].append((v, len2))



if __name__ == "__main__":
    n, m = map(int, input().split())

    adj = [[] for _ in range(MAXN)]
    graph = [[] for _ in range(MAXN)]

    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        adj[u].append((v, w))

        graph[v].append((u, w))
        adj[v].append((u, w))

    add_new_edge(n)

    vis = [False] * MAXN
    distances = dijkstra(1)

    result = []
    for i in range(1, n + 1):
        if distances[i] >= INF:
            result.append(-1)
        else:
            result.append(distances[i])

    print(" ".join(map(str, result)))
