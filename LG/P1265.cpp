#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-15
 *  @Time: 15:55
 *  To change this template use File | Settings | File Templates.
 * 
 */

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
#define maxn 15000000
#define maxn2 5005
int n, m, s;
bool vis[maxn2];
double ans = 0;
double dis[maxn2];
struct node {
    double x;
    double y;
} nodes[maxn2];


inline double cal(int x, int y) {
    return sqrt((nodes[x].x - nodes[y].x) * (nodes[x].x - nodes[y].x) +
                (nodes[x].y - nodes[y].y) * (nodes[x].y - nodes[y].y));
}

void Prim() {
    int pos = 0;
    double temp;
    dis[1] = 0;
    loop(i, 1, n) {
        temp = INF;
        loop(j, 1, n) {
            if (!vis[j] && temp > dis[j]) {
                pos = j;
                temp = dis[j];
            }
        }
        vis[pos] = 1;
        ans += temp;
        loop(j, 1, n) {
            double dd = cal(pos, j);
            if (dd < dis[j]) {
                dis[j] = dd;
            }
        }
    }
}

int P1265() {
    cin >> n;
    loop(i, 1, n) {
        cin >> nodes[i].x >> nodes[i].y;
        dis[i] = INF;
    }
    mset(vis, 0);
    Prim();
    printf("%.2f", ans);
    return 0;
}
