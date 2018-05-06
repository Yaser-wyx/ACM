#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-04
 *  @Time: 16:21
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 100005
int n;

int P1969() {
    cin >> n;
    int cnt = 0;
    int last = 0;
    int now;
    loop(i, 1, n) {
        cin >> now;
        if (now > last) {
            cnt += (now - last);
        }
        last = now;
    }

    cout << cnt << endl;
    return 0;
}
