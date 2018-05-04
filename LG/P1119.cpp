#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-14
 *  @Time: 16:37
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 300
#define INF 777777777
int n, m;
int times[maxn];
int cities[maxn][maxn];

int P1119() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    times[n] = INF;
    int a, b, w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cities[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        cities[a][b] = w;
        cities[b][a] = w;
    }
    for (int i = 0; i < n; i++)
        cities[i][i] = 0;
    int q;
    scanf("%d", &q);
    int u, v, t;
    int k = 0;//前k个节点
    while (q--) {//第Q次询问
        scanf("%d%d%d", &u, &v, &t);
        while (times[k] <= t) {//判断前k个节点的时间是否小于此次查询的时间
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cities[i][j] = min(cities[i][k] + cities[k][j], cities[i][j]);
                }
            }
            k++;//节点自增
        }
        if (cities[u][v] != INF && times[u] <= t && times[v] <= t) {//如果可以访问，且起始节点和终点都大于t
            printf("%d\n", cities[u][v]);
        } else {
            printf("-1\n");
        }
    }
    return 0;

}