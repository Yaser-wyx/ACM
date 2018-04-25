#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-22
 *  @Time: 20:30
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define maxn 1010
#define maxm 250
int n, m, k;
int value[maxn];
int dp[maxn];

void caculate() {
    loop(i, 2, n) {
        set<int> temp;
        temp.insert(1);
        for (int j = 2; j <= i / 2; j++) {
            int x = i / j;
            if (x * j == i) {
                temp.insert(x);
                temp.insert(j);
            }
        }
        int v = 0;
        while (!temp.empty()) {
            v += *temp.begin();
            temp.erase(temp.begin());
        }
        value[i] = v;
    }
}

int P1734() {
    scanf("%d", &n);
    mset(value, 0);
    caculate();
    loop(i, 2, n) {
        loop2(j, n, i) {
            dp[j] = max(dp[j], dp[j - i] + value[i]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}