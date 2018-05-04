#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-24
 *  @Time: 11:13
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100000
typedef unsigned long long int lli;
int n, k;
int ans = 0;
//因为要不重复，所以每一次划分后的一组数要保证升序
void dfs(int last, int s, int nn) {
    if (s == 1) {
        ans++;
        return;
    }
    for (int i = last; i <= nn / s; i++) {
        dfs(i, s - 1, nn - i);
    }

}

int P1025() {

    scanf("%d%d", &n, &k);
    dfs(1, k, n);
    printf("%d\n", ans);

}