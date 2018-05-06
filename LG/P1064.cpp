#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-16
 *  @Time: 17:03
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 32100
int n, m;

int P1064() {
    pair<int, int> primary[100];//主件
    vector<pair<int, int> > groups[100];//分组
    int dp[maxn];
    scanf("%d%d", &n, &m);
    int v, p, q;
    for (int i = 1; i < 100; i++) {
        pair<int, int> temp(0, 0);//预先添加一个空物品，这是给主件的一个占位符
        groups[i].push_back(temp);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &v, &p, &q);
        if (q == 0) {
            primary[i].first = v;
            primary[i].second = p * v;
        } else {
            int len = groups[q].size();
            for (int j = 0; j < len; j++) {//附件组合
                int cost = groups[q][j].first + v;
                int value = groups[q][j].second + p * v;
                pair<int, int> temp(cost, value);
                groups[q].push_back(temp);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < groups[i].size() && primary[i].first; j++) {//添加主件信息
            groups[i][j].first += primary[i].first;
            groups[i][j].second += primary[i].second;
        }
    }
    //分组背包
    for (int i = 1; i <= m; i++) {//不同的分组
        for (int k = n; k >= 0 && groups[i].size(); k--) {//费用
            for (int j = 0; j < groups[i].size(); j++) {//遍历每一个分组，注意循环顺序不可更改
                if (k >= groups[i][j].first) {
                    dp[k] = max(dp[k], dp[k - groups[i][j].first] + groups[i][j].second);//前i个分组，在花费k的情况下的最大价值
                }
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}