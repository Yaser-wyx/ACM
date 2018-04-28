#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-27
 *  @Time: 19:23
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
#define maxn 30
#define maxm 10005
int n, sum;
int nums[maxn];
bool vis[maxn];
bool flag;
int c[maxn];

inline lli fac(int x) {
    lli ans = 1;
    if (x == 0) {
        return ans;
    }
    loop(i, 2, x) {
        ans *= i;
    }
    return ans;

}

void caculate(int m) {
    //系数计算
    //C(n,m)=n!/[m!(n-m)!]
    lli a = fac(m);
    loop(i, 0, m) {
        c[i] = a / (fac(i) * fac(m - i));
    }
}

bool judge(int x) {
    int temp = 0;
    loop(i, 0, x) {
        temp += (nums[i] * c[i]);
        if (temp > sum) {
            return false;
        }
    }
    if (x == n - 1) {
        return temp == sum;
    }
    return true;

}

void dfs(int index) {
    if (index == n) {
        flag = true;
        loop3(i, 0, n) {
            cout << nums[i];
            if (i != n) {
                cout << " ";
            }
        }
        return;
    }
    loop(i, 1, n) {
        if (!vis[i]) {
            vis[i] = 1;
            nums[index] = i;
            if (judge(index)) {
                dfs(index + 1);
            } else {
                vis[i] = 0;
                return;
            }
            if (flag) {
                return;
            }
            vis[i] = 0;
        }
    }

}

int P1118() {
    cin >> n >> sum;
    mset(vis, 0);
    mset(nums, 0);
    mset(c, 0);

    flag = false;
    caculate(n - 1);
    dfs(0);
    return 0;
}
