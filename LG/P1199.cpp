#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-12
 *  @Time: 18:01
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
#define maxn 505
#define Mod 10007

int n, m, t;
int nums[maxn][maxn];

int P1199() {

    cin >> n;
    int temp;
    vector<int> values;
    loop(i, 1, n) {
        loop(j, i + 1, n) {
            cin >> temp;
            nums[i][j] = nums[j][i] = temp;
        }
    }
    int ans = 0;
    loop(i, 1, n) {
        sort(nums[i] + 1, nums[i] + 1 + n, [](int a, int b) {
            return a > b;
        });
        ans = max(ans, nums[i][2]);
    }

    cout << 1 << endl << ans;

    return 0;
}
 