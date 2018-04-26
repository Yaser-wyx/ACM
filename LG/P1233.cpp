#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-26
 *  @Time: 09:51
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

int P1233() {

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
