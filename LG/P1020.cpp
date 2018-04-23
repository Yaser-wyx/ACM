#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-16
 *  @Time: 21:25
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 100010
int n, m;
int pre[maxn];
int len = 0;
int dp[maxn];

int binary(int x) {
    int l = 0;
    int r = len;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (dp[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;

}

int main() {
    int index = 0;
    while (~scanf("%d", &pre[index]))index++;
    int system[maxn];
    mset(dp, 0);
    int cnt = 0;
    len = 0;
    dp[0] = pre[index];
    system[0] = pre[index];
    for (int i = index - 1; i >= 0; i--) {
        if (dp[len] <= pre[i]) {
            dp[++len] = pre[i];
        } else {
            int inx = binary(pre[i]);
            dp[inx] = pre[i];
        }
        int inx = -1;
        int dis = 99999999;
        for (int j = 0; j <= cnt; j++) {
            if (system[j] <= pre[i]) {
                int temp = abs(system[j] - pre[i]);
                if (dis > temp) {
                    dis = temp;
                    inx = j;
                }
            }
        }

        if (inx == -1) {
            system[++cnt] = pre[i];
        } else {
            system[inx] = pre[i];
        }
    }
    printf("%d\n%d", len, cnt + 1);
    return 0;
}