#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-12
 *  @Time: 20:08
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
int nums[maxn];

int P1288() {
    cin >> n;
    loop(i, 1, n) {
        cin >> nums[i];
    }
    int left = 0, right = 0;
    loop(i, 1, n) {
        if (nums[i]) {
            left++;
        } else {
            break;
        }
    }
    loop2(i, n, 1) {
        if (nums[i]) {
            right++;
        } else {
            break;
        }
    }
    if (left % 2 || right % 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}