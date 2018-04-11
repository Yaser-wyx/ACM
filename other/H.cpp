#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 15:56
 *  To change this template use File | Settings | File Templates.
 * 
 */
int n, m;

int H() {
    scanf("%d%d", &n, &m);
    int ans = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i += 3) {
        sum1 += m;
    }
    for (int i = 0; i < m; i += 3) {
        sum2 += n;
    }
    ans = max(sum1, sum2);
    printf("%d\n", ans);
    return 0;
}