#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-17
 *  @Time: 18:16
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define mid (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 20005
#define maxn2 200005
int n, m, cnt = 0;
int head[maxn];
int color[maxn];
struct edge {
    int to;
    int next;
    int w;
} edges[maxn2];

inline void add(int from, int to, int w) {
    cnt++;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    edges[cnt].w = w;
    head[from] = cnt;
}

bool bfs(int md) {
    mset(color, 0);
    queue<int> queue1;
    loop(i, 1, n) {
        if (color[i]) {
            continue;
        }
        queue1.push(i);
        color[i] = 1;
        while (!queue1.empty()) {
            int nd = queue1.front();
            queue1.pop();
            for (int k = head[nd]; k != -1; k = edges[k].next) {
                if (edges[k].w >= md) {
                    int to = edges[k].to;
                    if (!color[to]) {
                        color[to] = color[nd] == 1 ? 2 : 1;
                        queue1.push(to);
                    } else {
                        if (color[to] == color[nd]) {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int P1525() {
    mset(head, -1);
    cin >> n >> m;
    int u, v, w;
    int l = 0, r = -2;

    loop(i, 1, m) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
        r = max(r, w);
    }
    int md;
    r++;
    while (l + 1 < r) {
        md = mid;
        if (bfs(md)) {
            r = md;
        } else {
            l = md;
        }
    }
    cout << l;


    return 0;
}

