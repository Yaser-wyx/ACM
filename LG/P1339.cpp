#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-28
 *  @Time: 11:38
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 10000
#define maxm 20005
int t, c, ts, te;
int head[maxn << 1];
int cnt = 0;

struct edge {
    int to;
    int next;
    int weight;

    bool operator<(const edge &rhs) const {
        return weight > rhs.weight;
    }
} edges[maxn << 1];

void add(int a, int b, int w) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].weight = w;
    edges[cnt].next = head[a];
    head[a] = cnt;
}

bool vis[5010];
int dis[5010];
priority_queue<edge> queue1;

void Dijkstra() {
    dis[ts] = 0;
    vis[ts] = 1;
    for (int i = head[ts]; i != -1; i = edges[i].next) {
        queue1.push(edges[i]);
    }
    while (!queue1.empty()) {
        edge edge1 = queue1.top();
        queue1.pop();
        if (vis[edge1.to]) {
            continue;
        }
        vis[edge1.to] = 1;
        dis[edge1.to] = edge1.weight;
        for (int i = head[edge1.to]; i != -1; i = edges[i].next) {
            edge temp = edges[i];
            if (!vis[temp.to]) {
                temp.weight += edge1.weight;
                queue1.push(temp);
            }
        }

    }
}

int P1339() {
    mset(head, -1);
    mset(vis, 0);
    cin >> t >> c >> ts >> te;
    int a, b, w;
    loop3(i, 0, c) {
        cin >> a >> b >> w;
        add(a, b, w);
        add(b, a, w);
    }
    Dijkstra();
    cout << dis[te];
    return 0;
}

 