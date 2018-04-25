#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 20:31
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
#define maxn 100
#define maxm 20
int n, m, k;
string str1;
string str2;


void build(string before, string after) {
    if (after.size() > 0) {
        char c = after[after.size() - 1];
        printf("%c", c);
        int index = before.find(c);
        build(before.substr(0, index), after.substr(0, index));
        build(before.substr(index + 1), after.substr(index, after.size() - index - 1));
    }
}

int P1030() {
    cin >> str1 >> str2;
    build(str1, str2);

    return 0;
}