#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-14
 *  @Time: 20:18
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 200005
int n, m, s;
int nxt[maxn];
int ans = 7777777;
bool vis[maxn];
int dis;
int seg[maxn];


void search(int x) {
    int next = nxt[x];
    while (!vis[next]) {
        vis[next] = 1;
        dis++;
        next = nxt[next];
    }

}

int P2661_2() {
    cin >> n;
    mset(seg, 0);
    loop(i, 1, n) {
        cin >> nxt[i];
        seg[nxt[i]]++;
    }
    loop(i, 1, n) {
        if (seg[i] == 0) {
            if (!vis[i]) {
                vis[i] = 1;
                seg[nxt[i]]--;
                int to = nxt[i];
                while (seg[to] == 0) {
                    if (!vis[to]) {
                        vis[to] = 1;
                        to = nxt[to];
                        seg[to]--;//删边
                    }
                }
            }

        }
    }
    mset(vis, 0);
    loop(i, 1, n) {
        if (vis[i] || seg[i] == 0) {
            continue;
        }

        vis[i] = 1;
        dis = 1;
        search(i);
        ans = min(ans, dis);
    }
    cout << ans;
    return 0;
}