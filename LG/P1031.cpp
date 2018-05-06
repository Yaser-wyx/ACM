#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-09
 *  @Time: 20:38
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t) memset(t,0,sizeof(t))
#define maxn 105
typedef long long int lli;

int P1031() {
    int n;
    int a[maxn];

    scanf("%d", &n);
    mset(a);
    lli sum = 0;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        sum += temp;
        a[i] = temp;
    }
    int avg = sum / n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i] -= avg;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != 0) {//如果当前堆为0则不需要移动了
            a[i + 1] += a[i];//否则将当前堆多出的（或少的）移到下一堆
            cnt++;
            a[i] = 0;
        }
    }
    printf("%d\n", cnt);

    return 0;
}