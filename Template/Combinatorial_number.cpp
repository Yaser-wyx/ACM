#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-05
 *  @Time: 17:42
 *  To change this template use File | Settings | File Templates.
 *  组合数计算
 */
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 30
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
