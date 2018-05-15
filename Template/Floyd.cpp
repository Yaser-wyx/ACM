#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-14
 *  @Time: 12:06
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
#define maxn 10005
int n, m, s;
int dis[maxn][maxn];

void floyd() {
    loop(k, 1, n) {
        loop(i, 1, n) {
            loop(j, 1, n) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

void init() {
    cin >> n >> m >> s;
    int v, u, weight;
    loop(i, 0, n) {
        loop(j, 0, n) {
            if (i == j) {
                dis[i][j] = 0;
            } else {
                dis[i][j] = 7777;
            }
        }
    }
    loop3(i, 0, m) {
        cin >> v >> u >> weight;
        dis[v][u] = weight;
    }

    floyd();
}