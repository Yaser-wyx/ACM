#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-30
 *  @Time: 09:34
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

lli fac[33] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144,
               524288,
               1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,
               1073741824, 2147483648, 4294967296};

int P1582() {
    cin >> n >> k;
    if (n <= k) {
        cout << 0;
        return 0;
    }
    int index = lower_bound(fac, fac + 33, n) - fac;
    if (fac[index] > n) {
        index--;
    } else {
        //相等
        cout << 0;
        return 0;
    }
    while (k-- > 1) {
        while (fac[index] > n) {
            index--;
        }
        n -= fac[index];
        if (n <= 1) {
            cout << 0;
            return 0;
        }
    }
    index = 0;
    while (++index) {
        if (fac[index] >= n) {
            cout << fac[index] - n;
            break;
        }
    }

    return 0;
}
