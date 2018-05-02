#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-02
 *  @Time: 10:50
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
#define maxn 2005
#define maxm 20005
lli l, m, k, n, r, q;
char ans[maxn];
char a[maxn];
char b[maxn];
char tr[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
               'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
    cin >> n >> a >> b;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len;
    len = min(len_a, len_b);
    int index_a = len_a - 1;
    int index_b = len_b - 1;
    int x, y, z;
    bool flag = 0;
    loop3(i, 0, len) {
        char a1 = a[index_a--];
        char b1 = b[index_b--];
        if (a1 >= '0' && a1 <= '9') {
            x = a1 - '0';
        } else {
            x = a1 - 'A' + 10;
        }

        if (b1 >= '0' && b1 <= '9') {
            y = b1 - '0';
        } else {
            y = b1 - 'A' + 10;
        }
        z = x + y + flag;
        flag = 0;
        if (z >= n) {
            z -= n;
            flag = 1;
        }
        ans[i] = tr[z];
    }
    int index = strlen(ans);

    if (len_a > len_b) {
        loop2(i, index_a, 0) {
            char a1 = a[i];
            if (a1 >= '0' && a1 <= '9') {
                x = a1 - '0';
            } else {
                x = a1 - 'A' + 10;
            }

            z = x + flag;
            flag = 0;
            if (z >= n) {
                z -= n;
                flag = 1;
            }
            ans[index++] = tr[z];
        }
    } else {
        loop2(i, index_b, 0) {
            char a1 = b[i];
            if (a1 >= '0' && a1 <= '9') {
                x = a1 - '0';
            } else {
                x = a1 - 'A' + 10;
            }
            z = x + flag;
            flag = 0;
            if (z >= n) {
                z -= n;
                flag = 1;
            }
            ans[index++] = tr[z];
        }
    }
    if (flag) {
        ans[strlen(ans)] = '1';
    }
    loop2(i, strlen(ans) - 1, 0) {
        cout << ans[i];
    }
    return 0;
}

 