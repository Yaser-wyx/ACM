#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-27
 *  @Time: 14:58
 *  To change this template use File | Settings | File Templates.
 * 
 */
namespace c {


#define maxn 751000
    using namespace std;
    int father[maxn];
    vector<int> cities[maxn];
    bool vis[maxn];
    int sum[maxn][3];

    void dfs(int now) {
        if (cities[now].size() == 0) {
            return;
        }
        for (int city:cities[now]) {
            if (!vis[city]) {
                //没有访问过
                vis[city] = true;
                father[city] = now;
                dfs(city);
            }
        }
    }
}
using namespace c;

int C() {
    int N, Q;
    scanf("%d%d", &N, &Q);

    for (int i = 0; i < N - 1; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        //建立无向图
        cities[t1].push_back(t2);
        cities[t2].push_back(t1);
    }
    memset(vis, false, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    vis[1] = true;
    father[1] = 0;
    dfs(1);
    while (Q--) {
        int q;
        scanf("%d", &q);
        sum[q][1]++;
        sum[q][2]++;
        sum[father[q]][0]++;
        sum[father[q]][1]++;
        sum[father[father[q]]][0]++;
        printf("%d\n", sum[q][0] + sum[father[q]][1] + sum[father[father[q]]][2]);
    }

}