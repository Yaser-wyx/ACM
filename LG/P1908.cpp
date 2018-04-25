#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 16:52
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 40005
#define maxm 20
int n, m, k;
pair<int, int> nodes[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

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

int P1908() {
    scanf("%d", &n);
    mset(sum, 0);
    loop(i, 1, n) {
        scanf("%d", &nodes[i].second);
        nodes[i].first = i;
    }
    sort(nodes + 1, nodes + 1 + n, cmp);
    int res = 0;
    loop(i, 1, n) {
        update(nodes[i].first);
        res += (i - getSum(nodes[i].first));
    }
    printf("%d\n", res);

    return 0;
}
 