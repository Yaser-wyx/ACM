#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-14
 *  @Time: 15:24
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 200
#define INF 777777777
int n, a, b;

int dis[maxn][maxn];
int P1346(){
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = 0;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            if (!j) { dis[i][v] = 0; } else { dis[i][v] = 1; }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    if (dis[a][b] != INF) {
        printf("%d\n", dis[a][b]);
    } else {
        printf("-1\n");
    }
    return 0;

}