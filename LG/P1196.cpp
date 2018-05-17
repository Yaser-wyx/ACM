#include <bits/stdc++.h>

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-16
 *  @Time: 18:10
 *  To change this template use File | Settings | File Templates.
 * 
 */

int read() {
    int rv = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        rv = (rv << 1) + (rv << 3) + c - '0';
        c = getchar();
    }
    return rv * fh;
}

using namespace std;
typedef long long int lli;
typedef __int128 big;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
#define Mod 2000120420010122
#define all(x) x.begin(),x.end()
#define in  std::ios::sync_with_stdio(false);fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 30005
#define maxn2 10
int n, m, t, k;
int num[maxn];//以该点为头，它的孩子的数量
int dis[maxn];//与祖先的距离
int fa[maxn];

void init(int n) {
    loop(i, 0, n) {
        fa[i] = i;
        dis[i] = 0;
        num[i] = 1;
    }
}

int find(int v) {
    if (fa[v] == v) {
        return fa[v];
    }
    int fn = find(fa[v]);//找祖先
    dis[v] += dis[fa[v]];
    return fa[v] = fn;

}

void union2(int u, int v) {
    int x = find(u);
    int y = find(v);
    dis[x] += num[y];
    fa[x] = y;
    num[y] += num[x];
    num[x] = 0;
}

int query(int u, int v) {
    if (find(u) == find(v)) {
        int a = dis[u];
        int b = dis[v];
        return abs(a - b) - 1;
    } else {
        return -1;
    }
}


int P1196() {
    init(maxn);
    t = read();
    char cmd;
    int u, v;
    while (t--) {
        scanf(" %c", &cmd);
        u = read();
        v = read();
        if (cmd == 'M') {
            union2(u, v);
        } else {
            printf("%d\n", query(u, v));

        }
    }

    return 0;
}


 