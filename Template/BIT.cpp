#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-06
 *  @Time: 10:24
 *  To change this template use File | Settings | File Templates.
 *  树状数组
 */
#define maxn 40005
int n, m, k;
int sum[maxn];
int lowbit(int x) {
    return x & -x;
}

void update(int x) {
    while (x <= n) {
        sum[x]++;
        x += lowbit(x);
    }
}

int getSum(int x) {
    int ans = 0;
    while (x != 0) {
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;

}
