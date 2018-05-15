#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-14
 *  @Time: 11:04
 *  To change this template use File | Settings | File Templates.
 *  前向星存图，队列优化Dijkstra
 */
#define INF 2147483647
#define infinitesimal  -2100000000
#define all(x) x.begin(),x.end()
#define in  std::ios::sync_with_stdio(false);fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 10005

int n, m, t, s;
int head[maxn];
int cnt = 0;
int dis[maxn];
int vis[maxn];
struct edges {
    int to;
    int next;
    int weight;
} edges[500005];

void add(int from, int to, int weight) {
    cnt++;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    edges[cnt].weight = weight;
    head[from] = cnt;
}

struct cmp {
    bool operator()(int x, int y) {
        return dis[x] > dis[y];
    }
};

void dijkstra() {
    priority_queue<int, vector<int>, cmp> queue1;//队列优化
    queue1.push(s);
    while (!queue1.empty()) {
        int u = queue1.top();
        queue1.pop();
        if (!vis[u]) {
            vis[u] = 1;//标记
            for (int nxt = head[u]; nxt != -1; nxt = edges[nxt].next) {
                int v = edges[nxt].to;
                dis[v] = min(dis[v], dis[u] + edges[nxt].weight);
                queue1.push(v);
            }
        }
    }
}

void init() {//初始化
    mset(head, -1);
    int u, v, weight;
    loop3(i, 0, m) {
        cin >> v >> u >> weight;
        add(v, u, weight);
    }
    loop(i, 0, n) {
        dis[i] = INF;
    }
    dis[s] = 0;
    mset(vis, 0);
    dijkstra();
}