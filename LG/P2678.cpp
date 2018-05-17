#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-29
 *  @Time: 09:45
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 50005
#define maxm 20005
lli l, m, n, minn, maxx;
lli stones[maxn];

int judge(int x) {
    int rev = 0;
    int st = 0;
    loop(i, 1, n) {
        if (stones[i] - st < x) {
            rev++;
        } else {
            st = stones[i];
        }
    }
    return rev <= m;
}

int P2678() {
    cin >> l >> n >> m;
    minn = 1;
    stones[0] = 0;
    loop(i, 1, n) {
        cin >> stones[i];
    }
    maxx = l;
    lli ans = 0;
    while (minn+1 <maxx) {
        lli mid = (maxx + minn) / 2;
        int temp = judge(mid);
        if (!temp) {
            //间隙太大,石头移除太多
            maxx = mid;
        } else {
            //间隙太小，石头移除太少
            minn = mid ;

        }
    }
    cout << minn;
    return 0;
}

 