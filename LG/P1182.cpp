#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 10:26
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100000
int pre[maxn];
int n, m;

inline bool judge(int test) {
    int k = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] + sum <= test) {
            sum += pre[i];
        } else {
            k++;
            sum = pre[i];
        }
    }
    return k >= m;

}

int P1182() {
    scanf("%d%d", &n, &m);

    int r = 0;
    int l = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        l = max(l, pre[i]);
        r += pre[i];
    }
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (judge(mid)) {
            //mid太小
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", l);

}