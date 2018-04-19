#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-19
 *  @Time: 21:13
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 210
#define maxm 50
int D, m;

struct rubbish {
    int time;
    int life;
    int height;

    bool operator<(const rubbish &rhs) const {
        return time < rhs.time;
    }
} rubbishes[maxn];


int P1156() {
    int dp[maxn];
    scanf("%d%d", &D, &m);
    loop(i, 1, m) {
        scanf("%d%d%d", &rubbishes[i].time, &rubbishes[i].life, &rubbishes[i].height);
    }
    sort(rubbishes + 1, rubbishes + m + 1);
    mset(dp, -1);
    dp[0] = 10;
    loop(i, 1, m) {
        for (int h = D; h >= 0; h--) {
            if (dp[h] >= rubbishes[i].time) {//可以坚持到该垃圾的到来
                if (h + rubbishes[i].height >= D) {//可以活着走出去
                    printf("%d\n", rubbishes[i].time);
                    return 0;
                }
                dp[h + rubbishes[i].height] = max(dp[h], dp[h + rubbishes[i].height]);//堆垃圾
                dp[h] += rubbishes[i].life;//吃下垃圾
            }
        }
    }
    printf("%d\n", dp[0]);//走不出去

    return 0;
}
