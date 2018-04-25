#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 17:45
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
#define maxn 3000
#define maxm 20
int n, m, k;
string str;
int len;

char judge(string s) {
    int zero = s.find('0');
    int one = s.find('1');
    if (zero < s.length() && one < s.length()) {
        return 'F';
    } else if (zero < s.length()) {
        return 'B';
    } else {
        return 'I';
    }
}

struct node {
    char flag;
    string s;

    string split(bool b) {
        string temp;
        if (!b) {
            //左
            temp = s.substr(0, s.length() / 2);
        } else {
            //右
            temp = s.substr(s.length() / 2);
        }
        return temp;
    }
} nodes[maxn];

void build(int index) {
    if (lson >= n) {
        return;
    }
    string left = nodes[index].split(0);
    string right = nodes[index].split(1);
    nodes[lson].s = left;
    nodes[lson].flag = judge(left);
    nodes[rson].s = right;
    nodes[rson].flag = judge(right);
    build(lson);
    build(rson);
}

void print(int index) {
    if (index >= n) {
        return;
    }
    print(lson);
    print(rson);
    printf("%c", nodes[index].flag);
}

int P1087() {
    scanf("%d", &n);
    n = pow(2, n + 1);
    cin >> str;
    nodes[1].s = str;
    nodes[1].flag = judge(str);
    build(1);
    print(1);
    return 0;
}