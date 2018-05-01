#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-30
 *  @Time: 10:17
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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);

}

int P1170() {
    cin >> n;
    int x, y, x1, y1;
    while (n--) {
        cin >> x >> y >> x1 >> y1;
        if (gcd(abs(x - x1), abs(y - y1)) == 1) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }

    }

    return 0;
}

 