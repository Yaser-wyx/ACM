#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-30
 *  @Time: 12:40
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
#define maxn 50005
#define maxm 20005
lli l, m, k, n, minn, maxx, r, q;
int ans[maxn];

int P1338() {
    mset(ans, 0);
    cin >> n >> m;
    int st = 0;
    int ed = n - 1;
    loop(i, 1, n) {
        lli temp = (n - i - 1) * (n - i) / 2;//最大逆序数个数
        if (m <= temp) {//如果n-1个数的逆序数个数不大于逆序数个数
            ans[st++] = i;//将当前最小的数放前面
        } else {
            ans[ed--] = i;//否则放后面
            m -= (ed - st + 1);//减去可以贡献的逆序数个数
        }
    }
    loop3(i, 0, n) {
        cout << ans[i]<<" ";
    }
    return 0;
}