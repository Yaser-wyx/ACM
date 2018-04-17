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
    int start[maxn];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        tasks[i].first = a;
        tasks[i].second = b + a;
        start[a]++;
    }
    sort(tasks, tasks + m, cmp);
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (start[i]) {
            for (; tasks[cnt].first==i; cnt++) {
                dp[i] = max(dp[tasks[cnt].second], dp[i]);
            }
        } else {
            dp[i] = dp[i + 1] + 1;
        }
    }
    printf("%d\n", dp[1]);
    return 0;
}