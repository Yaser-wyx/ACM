#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-27
 *  @Time: 20:03
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
#define maxn 100005
#define maxm 10005
int n, sum;
int letters[30];//对应字母出现的最后一个位置

struct node {
    char c;
    int size;

    node(char c, int size) : c(c), size(size) {}
};

int A() {
    char c[maxn];
    mset(letters, -1);
    cin >> c;
    loop3(i, 0, strlen(c)) {
        int x = c[i] - 97 + 1;
        letters[x] = max(letters[x], i);
    }
    queue<node> ans;
    int last = -1;
    loop2(i, 26, 1) {
        if (letters[i] > last) {
            last = letters[i];
            node temp(i + 97 - 1, letters[i]);
            ans.push(temp);
        }
    }
    node now = ans.front();
    ans.pop();

    loop3(i, 0, strlen(c)) {
        if (i > now.size) {
            now = ans.front();
            ans.pop();
        }
        if (c[i] == now.c) {
            cout << c[i];
        }

    }
    return 0;
}

 