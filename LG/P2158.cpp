#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-30
 *  @Time: 11:07
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 1000005
#define maxm 20005
lli l, m, k, n, minn, maxx, r, q;
int euler[400001];

void Euler(int Max) {
    Max = n - 1;
    euler[1] = 1;
    for (int i = 2; i <= Max; i++)
        euler[i] = i;
    for (int i = 2; i <= Max; i++)
        if (euler[i] == i)
            for (int j = i; j <= Max; j += i)
                euler[j] = euler[j] / i * (i - 1);
}

int P2158() {
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    Euler(n);
    int ans = 0;
    loop3(i, 1, n) {
        ans += euler[i];
    }
    cout << ((ans << 1) | 1);
    return 0;
}
