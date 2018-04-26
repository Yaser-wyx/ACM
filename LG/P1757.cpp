#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-26
 *  @Time: 08:44
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
#define maxn 1005
#define maxm 10005
int n, m, t;

struct node {
    int cost;
    int value;

    node(int cost, int value) : cost(cost), value(value) {}
};

vector<node> groups[maxn];
int dp[maxn];

int P1757() {
    scanf("%d%d", &m, &n);
    int a, b, c;
    int g = 0;
    loop(i, 1, n) {
        scanf("%d%d%d", &a, &b, &c);
        node good(a, b);
        groups[c].push_back(good);//加入分组
        g = max(g, c);
    }
    mset(dp, 0);
    loop(k, 1, g) {//遍历分组
        if (!groups[k].size()) {
            continue;
        }
        loop2(j, m, 0) {//背包容量
            loop3(i, 0, groups[k].size()) {//遍历每一个分组里的物品
                if (j >= groups[k][i].cost) {
                    dp[j] = max(dp[j], dp[j - groups[k][i].cost] + groups[k][i].value);
                } else {
                    dp[j] = dp[j];
                }
            }
        }
    }
    printf("%d\n", dp[m]);

    return 0;
}
