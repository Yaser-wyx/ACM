#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-29
 *  @Time: 20:01
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
lli l, m, n, minn, maxx, r, q;
int pre[maxn];

void create() {
    pre[0] = pre[1] = 0;
    loop(i, 2, m) {
        pre[i] = 1;
    }
    loop(i, 2, m) {
        if (pre[i]) {
            for (int j = i << 1; j <= m; j += i) {
                pre[j] = 0;
            }
        }
    }
    loop(i, 2, m) {
        pre[i] += pre[i - 1];
    }
}

int P1865() {
    cin >> n >> m;
    create();
    int l, r;
    loop(i, 1, n) {
        cin >> l >> r;
        if (l >= 1 && l <= m && l <= r && r >= 1 && r <= m) {
            cout << (pre[r] - pre[l - 1]) << endl;
        } else {
            cout << "Crossing the line" << endl;
        }
    }
    return 0;
}

 