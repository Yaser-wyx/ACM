#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-14
 *  @Time: 11:20
 *  To change this template use File | Settings | File Templates.
 *
 */

#define INF 2147483647
#define infinitesimal  -2100000000
#define Mod 2000120420010122
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
int n, m, s;
int head[maxn];
int cnt = 0;
struct edge {
    int next;
    int to;
    int weight;
} edges[500005];
int dis[maxn];
bool vis[maxn];

inline void add(int from, int to, int weight) {
    cnt++;
    edges[cnt].next = head[from];
    edges[cnt].to = to;
    edges[cnt].weight = weight;
    head[from] = cnt;
}

bool relax(int v, int i) {
    int d = dis[v] + edges[i].weight;
    int u = edges[i].to;
    if (d < dis[u]) {
        dis[u] = d;
        return 1;
    }
    return 0;

}

void SPFA() {
    queue<int> queue1;
    queue1.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!queue1.empty()) {
        int v = queue1.front();
        queue1.pop();
        vis[v] = 0;
        for (int i = head[v]; i != -1; i = edges[i].next) {
            int u = edges[i].to;
            if (relax(v, i) && !vis[u]) {
                vis[u] = 1;
                queue1.push(u);
            }
        }
    }
}

void init() {
    cin >> n >> m >> s;
    int v, u, weight;
    mset(head, -1);
    loop3(i, 0, m) {
        cin >> v >> u >> weight;
        add(v, u, weight);
    }
    loop(i, 0, n) {
        dis[i] = INF;
    }
    mset(vis, 0);
    SPFA();

}