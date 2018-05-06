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
int st[maxn];
bool vis[maxn];
bool flag;
int c[maxn];

inline lli fac(int x) {//阶乘计算
    lli ans = 1;
    if (x == 0) {
        return ans;
    }
    loop(i, 2, x) {
        ans *= i;
    }
    return ans;

}

void caculate(int m) {//组合数计算
    //系数计算
    //C(n,m)=n!/[m!(n-m)!]
    lli a = fac(m);
    loop(i, 0, m) {
        c[i] = a / (fac(i) * fac(m - i));
    }
}

bool judge(int x) {//判断当前生成的数列相加后是否小于等于最后剩下的那个
    int temp = 0;
    loop(i, 0, x) {
        temp += (st[i] * c[i]);
        if (temp > sum) {//大于
            return false;
        }
    }
    if (x == n - 1) {
        return temp == sum;//如果生成了最后一个数
    }
    return true;
}

void dfs(int index) {
    if (index == n) {
        flag = true;
        loop3(i, 0, n) {//输出答案
            cout << st[i];
            if (i != n) {
                cout << " ";
            }
        }
        return;
    }
    loop(i, 1, n) {
        if (!vis[i]) {
            vis[i] = 1;
            st[index] = i;
            if (judge(index)) {//判断生成的这个数是否合法
                dfs(index + 1);
            } else {
                vis[i] = 0;//回溯
                return;
            }
            if (flag) {//找到结果了
                return;
            }
            vis[i] = 0;
        }
    }

}

int P1118() {
    cin >> n >> sum;
    mset(vis, 0);
    mset(st, 0);
    mset(c, 0);
    flag = 0;
    caculate(n - 1);
    dfs(0);
    return 0;
}
