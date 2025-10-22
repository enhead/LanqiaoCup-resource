#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 1005
#define INF 1e18

typedef long long ll;
typedef struct pair {
    ll first;
    ll second;
} pair;

typedef struct Edge {
    int v;
    ll w;
    struct Edge *next;
} Edge;

typedef struct Heap {
    pair arr[MAXN*MAXN];
    int size;
} Heap;

Edge *graph[MAXN];
Edge *adj[MAXN];
ll dis[MAXN];
int vis[MAXN];
Heap *h;

void push(Heap *heap, pair p) {
    if (heap->size >= MAXN*MAXN) {
        printf("Heap is full\n");
        return;
    }
    heap->size++;
    int i = heap->size;
    while (i > 1 && heap->arr[i / 2].first > p.first) {
        heap->arr[i] = heap->arr[i / 2];
        i /= 2;
    }
    heap->arr[i] = p;
}

pair top(Heap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return (pair){0, 0};
    }
    return heap->arr[1];
}

void pop(Heap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return;
    }
    pair last = heap->arr[heap->size];
    heap->size--;
    int i = 1;
    int child;
    while (i * 2 <= heap->size) {
        child = i * 2;
        if (child != heap->size && heap->arr[child + 1].first < heap->arr[child].first) {
            child++;
        }
        if (last.first > heap->arr[child].first) {
            heap->arr[i] = heap->arr[child];
        } else {
            break;
        }
        i = child;
    }
    heap->arr[i] = last;
}


void add(int u, int v, ll w) {
    Edge *edge = (Edge*) malloc(sizeof(Edge));
    edge->v = v;
    edge->w = w;
    edge->next = graph[u];
    graph[u] = edge;
    edge = (Edge*) malloc(sizeof(Edge));
    edge->v = v;
    edge->w = w;
    edge->next = adj[u];
    adj[u] = edge;
}

void dijkstra(int s) {
    h = (Heap*) malloc(sizeof(Heap));
    h->size = 0;
    for (int i = 1; i < MAXN; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    push(h, (pair){0, s});
    while (h->size > 0) {
        pair top_element = top(h);
        int u = top_element.second;
        pop(h);
        if (vis[u]) continue;
        vis[u] = 1;
        for (Edge *edge = graph[u]; edge; edge = edge->next) {
            int v = edge->v;
            ll w = edge->w;
            ll new_dis = dis[u] + w;
            if (new_dis < dis[v]) {
                dis[v] = new_dis;
                push(h, (pair){dis[v], v});
            }
        }
    }
}

void addNewEdge(int n) {
    for (int pa = 1; pa <= n; pa++) {
        for (Edge *edge = adj[pa]; edge; edge = edge->next) {
            int v = edge->v;
            long long len1 = edge->w;
            for (Edge *edgeNext = adj[v]; edgeNext; edgeNext = edgeNext->next) {
                int v_next = edgeNext->v;
                long long len2 = edgeNext->w;
                if (len2 % len1 == 0 && pa != v_next) {
                    Edge *new_edge = (Edge*) malloc(sizeof(Edge)); // add new edge
                    new_edge->v = v_next;
                    new_edge->w = len2;
                    new_edge->next = graph[pa];
                    graph[pa] = new_edge;
                }
            }
        }
    }
}

void solve1(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    addNewEdge(n);
    memset(vis, 0, sizeof(vis));
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        if (dis[i] >= INF) {
            dis[i] = -1;
        }
        printf("%lld", dis[i]);
        if(i < n) printf(" ");
        else printf("\n");
    }
}
int solve2(){
    clock_t start_time, end_time;
    double cpu_time_used;

    // 记录开始时间
    start_time = clock();
    FILE *file = fopen("./data/data1.in", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int n, m;
    fscanf(file, "%d %d", &n, &m);
    printf("n = %d m = %d\n",n,m);
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        fscanf(file, "%d %d %lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

    fclose(file);

    addNewEdge(n);
    memset(vis, 0, sizeof(vis));
    dijkstra(1);

    for (int i = 1; i <= n; ++i) {
        if (dis[i] >= INF) {
            printf("-1 ");
        } else {
            printf("%lld ", dis[i]);
        }
    }
    end_time = clock();

    // 计算所用的CPU时间
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("CPU时间：%f 秒\n", cpu_time_used);
    return 0;
}
int main() {
    solve1();
    return 0;
}
