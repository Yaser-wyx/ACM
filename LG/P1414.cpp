#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-10
 *  @Time: 21:15
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
#define maxn 10005
#define Mod 1000000007
int n, c;
int cnt[1000005];

int P1414() {
    cin >> n;
    int temp;
    int mx = 0;
    mset(cnt, 0);
    loop(i, 1, n) {
        cin >> temp;
        mx = max(mx, temp);
        int x = sqrt(temp);
        loop(j, 1, x) {
            if (temp % j == 0) {
                cnt[j]++;
                if (temp != j * j) {
                    cnt[temp / j]++;
                }
            }
        }
    }

    loop(i, 1, n) {
        while (cnt[mx] < i) {
            mx--;
        }
        cout << mx << endl;
    }

    return 0;
}