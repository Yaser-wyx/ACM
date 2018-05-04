#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-02
 *  @Time: 15:35
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
int n;
char necklace[maxn];

int P1203() {
    cin >> n;
    loop3(i, 0, n) {
        cin >> necklace[i];
        necklace[i + n] = necklace[i];
    }
    int ans = 0;
    loop3(i, 0, n) {
        int cnt = 1;
        bool vis[maxn];
        mset(vis, 0);
        vis[i] = 1;
        char flag = necklace[i];
        loop3(j, i + 1, i + n) {
            if (flag == 'w' && necklace[j] != 'w') {
                flag = necklace[j];
            }
            if (necklace[j] == flag || necklace[j] == 'w') {
                cnt++;
                vis[j] = 1;
            } else {
                break;
            }
        }
        flag = necklace[i + n - 1];
        if (vis[i + n - 1]) {
            ans = max(ans, cnt);
            continue;
        } else {
            cnt++;
        }
        loop2(j, i + n - 2, i) {
            if (flag == 'w' && necklace[j] != 'w') {
                flag = necklace[j];
            }
            if (necklace[j] == flag || necklace[j] == 'w') {
                if (vis[j]) {
                    break;
                }
                cnt++;
            } else break;
        }
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}

 