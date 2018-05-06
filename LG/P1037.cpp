#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-05
 *  @Time: 10:24
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
#define maxn 35
int n, k;
bool matrix[maxn][maxn];
string nums;
const int L = 100005;
int na[L];
int cnt[maxn];

string mul(string a, int b)//高精度a乘单精度b
{
    string ans;
    int La = a.size();
    fill(na, na + L, 0);
    for (int i = La - 1; i >= 0; i--) na[La - i - 1] = a[i] - '0';
    int w = 0;
    for (int i = 0; i < La; i++) na[i] = na[i] * b + w, w = na[i] / 10, na[i] = na[i] % 10;
    while (w) na[La++] = w % 10, w /= 10;
    La--;
    while (La >= 0) ans += na[La--] + '0';
    return ans;
}


int P1037() {
    cin >> nums >> k;
    int a, b;
    loop3(i, 0, k) {
        cin >> a >> b;
        matrix[a][b] = 1;
    }
    mset(cnt, 0);
    loop(i, 0, 9)matrix[i][i] = 1;
    loop(k, 1, 9)loop(i, 0, 9) loop(j, 1, 9) if (matrix[i][k] && matrix[k][j])matrix[i][j] = 1;//floyd算法
    loop(i, 0, 9)loop(j, 0, 9)if (matrix[i][j])cnt[i]++;
    string ans = "1";
    loop3(i, 0, nums.length()) {
        int index = nums[i] - '0';
        ans = mul(ans, cnt[index]);
    }
    cout << ans;
    return 0;
}
