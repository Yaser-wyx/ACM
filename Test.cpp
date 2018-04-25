//#pragma GCC optimize(2)

#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 5005
#define maxm 10005
int n, m, k;
pair<int, int> club[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

int main() {
    in;
    scanf("%d", &n);
    loop(i, 1, n) {
        scanf("%d%d", &club[i].first, &club[i].second);
    }
    sort(club + 1, club + 1 + n, cmp);

    bool vis[maxn];
    mset(vis, 0);
    loop(i, 1, n) {
        if (!vis[i]) {
            int w = club[i].second;
            loop(j, i + 1, n) {
                if (vis[j]) {
                    continue;
                }
                if (club[j].second <= w) {
                    w = club[j].second;
                    vis[j] = 1;
                }
            }
        }
    }
    int ans = 0;
    loop(i, 1, n) {
        if (!vis[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
