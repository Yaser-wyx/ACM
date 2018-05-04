#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-02
 *  @Time: 14:46
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
#define maxn 5005
#define maxm 20005
lli n, s, a, b;

struct apple {
    int x;
    int y;

    bool operator<(const apple &rhs) const {
        return y < rhs.y;
    }
} apples[maxn];

int P1478() {
    cin >> n >> s >> a >> b;
    int heigh = a + b;
    int x, y;
    int index = 0;
    loop3(i, 0, n) {
        cin >> x >> y;
        if (x <= heigh) {
            apples[index].x = x;
            apples[index++].y = y;
        }
    }
    sort(apples, apples + index);
    int cnt = 0;
    loop3(i, 0, index) {
        if (apples[i].y <= s) {
            s -= apples[i].y;
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt;

    return 0;
}
