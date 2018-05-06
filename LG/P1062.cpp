#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-04
 *  @Time: 16:42
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
#define maxn 15
int n, k;
int x[maxn];

void transform(int num, int index) {
    if (num == 0) {
        return;
    }
    x[index] = num % 2;
    transform(num / 2, index + 1);
}

int P1062() {
    cin >> n >> k;
    transform(k, 0);
    lli ans = 0;
    loop(i, 0, 10) {
        if (x[i]) {
            ans += pow(n, i);
        }
    }
    cout << ans << endl;
    return 0;
}
