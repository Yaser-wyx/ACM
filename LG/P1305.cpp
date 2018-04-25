#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 21:28
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
#define maxn 500000
#define maxm 20
int n, m, k;
pair<int, int> tree[maxn];

void print(int index) {
    cout << (char) (index + 'a');
    if (tree[index].first >= 0) {
        print(tree[index].first);
    }
    if (tree[index].second >= 0) {
        print(tree[index].second);
    }

}


int P1305() {
    scanf("%d", &n);
    char root, left, right;
    int start = 0;
    loop(i, 1, n) {
        cin >> root >> left >> right;
        tree[root - 'a'].first = tree[root - 'a'].second = -1;
        if (i == 1) {
            start = root - 'a';
        }
        if (left != '*') {
            tree[root - 'a'].first = left - 'a';
        }
        if (right != '*') {
            tree[root - 'a'].second = right - 'a';
        }
    }
    print(start);
    return 0;
}