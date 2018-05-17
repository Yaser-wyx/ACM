#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-17
 *  @Time: 12:46
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define mid (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 200005
#define maxn2 10
lli n, p, m;
lli mx[maxn << 2];


inline void pushUp(int rt) {
    mx[rt] = max(mx[left], mx[right]);
}

lli query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) {
        return mx[rt];
    }
    int m = mid;
    lli ans = 0;
    if (L <= m) {
        ans = max(ans, query(L, R, lson));
    }
    if (R > m) {
        ans = max(ans, query(L, R, rson));
    }
    return ans;
}

void update(int index, lli v, int l, int r, int rt) {
    if (l == r) {
        mx[rt] = (v % p + p) % p;
        return;
    }
    int m = mid;
    if (index <= m) {
        update(index, v, lson);
    } else {
        update(index, v, rson);
    }
    pushUp(rt);

}

int P1198() {
    mset(mx, 0);
    cin >> m >> p;
    char op;
    lli last = 0;
    int index = 0;
    lli l = 0;
    loop(i, 1, m) {
        cin >> op >> l;
        if (op == 'A') {
            l += last;
            index++;
            update(index, l, 1, m, 1);

        } else {
            if (index == 0) {
                cout << 0 << endl;

            } else {
                last = query(index - l + 1, index, 1, m, 1);
                cout << last << endl;
            }
        }
    }
    return 0;
}


 