#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cstring>
#define real
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MAXN = 1e3 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj[MAXN];
vector<pair<int, int>> graph[MAXN];
ll dis[MAXN];
bool vis[MAXN];

void dijkstra(int s) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(dis, dis + MAXN, INF);
    fill(vis, vis + MAXN, false);
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto edge: graph[u]) {
            ll v = edge.first, w = edge.second;
            ll newDis = dis[u] + w;
            if (newDis < dis[v]) {
                dis[v] = newDis;
                pq.push({dis[v], v});
            }
        }
    }
}

void dfs(int u, int parent, int last) {
    if(vis[u]) return ;
    vis[u] = true;
    for (auto &x: adj[u]) {
        if (x.first == parent) continue;
        int v = x.first, w = x.second;
        if (last!=-1 && w % last == 0) graph[parent].emplace_back(v, w);
        dfs(v, u, w);
    }
}
void addNewEdge(int n){
    for(int i=1;i<=n;i++) {
        for (auto next: adj[i]) {
            for (auto nextNext: adj[next.first]) {
                int pa = i,v = nextNext.first;
                int len1 = next.second,len2 = nextNext.second;
                if(len2 % len1 == 0 && pa != v){
                    graph[pa].emplace_back(v,len2);
                }
            }
        }
    }
}
int main() {
#ifdef test
    int id = 20;
    // 获取当前时间点
    auto startTime = std::chrono::high_resolution_clock::now();


    ifstream inputFile("./data/data"+ to_string(id)+".in"); // 打开 input.in 文件
    std::streambuf *originalCinBuffer = std::cin.rdbuf(); // 保存原始 cin 缓冲区
    std::cin.rdbuf(inputFile.rdbuf()); // 将 input.in 文件的缓冲区设置为 cin 的缓冲区
#endif




    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        adj[u].emplace_back(v, w);

        graph[v].emplace_back(u, w);
        adj[v].emplace_back(u, w);
    }

    addNewEdge(n);

    dijkstra(1);

#ifdef real
    for (int i = 1; i <= n; ++i) {
        if (dis[i] >= INF) {
            dis[i] = -1;
        }
        cout << dis[i];
        if(i < n) cout  << " ";
        else cout << "\n";
    }
#endif

#ifdef test
    // 获取当前时间点
        auto endTime = std::chrono::high_resolution_clock::now();

        // 计算时间差
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        // 输出时间差
        std::cout << " 耗时: " << duration.count() << " 毫秒" << std::endl;
#endif
    return 0;
}
