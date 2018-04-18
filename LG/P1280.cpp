#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-17
 *  @Time: 14:53
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 10010
int n, m;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    pair<int, int> tasks[maxn];
    int dp[maxn];
    scanf("%d%d", &n, &m);
    int a, b;
    int start[maxn];//开始时间计数器
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        tasks[i].first = a;
        tasks[i].second = b + a;
        start[a]++;//自增
    }
    sort(tasks, tasks + m, cmp);
    int index = 0;//任务索引
    for (int i = n; i >= 1; i--) {
        if (start[i]) {//第i个时间是否有任务
            for (; tasks[index].first == i; index++) {//遍历任务
                dp[i] = max(dp[tasks[index].second], dp[i]);//去空闲时间最大的任务
            }
        } else {
            dp[i] = dp[i + 1] + 1;//没有任务
        }
    }
    printf("%d\n", dp[1]);
    return 0;
}