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
int mx[maxn];
int lowbit(int x) {
    return x & -x;
}

void update(int x) {
    while (x <= n) {
        mx[x]++;
        x += lowbit(x);
    }
}

int getSum(int x) {
    int ans = 0;
    while (x != 0) {
        ans += mx[x];
        x -= lowbit(x);
    }
    return ans;

}
