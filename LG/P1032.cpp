#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-16
 *  @Time: 15:27
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 50
#define maxn2 10
int n, m, s, k;
string a;
string b;
string tf[maxn2][2];//转换规则
int len = 0;

struct node {
    string str;
    int step;//步数
    node(string str, int step) : str(str), step(step) {}
};

int ans = 0;

bool change(string &str, int index, size_t &beg) {
    beg = str.find(tf[index][0], beg);
    if (beg != string::npos) {
        //找到了
        str.replace(beg, tf[index][0].length(), tf[index][1]);
        return 1;
    } else
        return 0;
}

bool bfs() {
    queue<node> queue1;
    node start(a, 0);
    queue1.push(start);
    while (!queue1.empty()) {
        node temp = queue1.front();
        queue1.pop();
        loop3(i, 0, len) {
            size_t beg = 0;
            while (beg < temp.str.length()) {
                string tt = temp.str;
                if (change(tt, i, beg)) {
                    if (tt == b) {
                        ans = temp.step + 1;
                        return 1;
                    }
                    if (temp.step < 10) {
                        node nxt(tt, temp.step + 1);
                        queue1.push(nxt);
                    }
                }
                if (beg == string::npos) {
                    break;
                }
                beg++;
            }

        }
    }
    return 0;
}

int P1032() {
    cin >> a >> b;
    while (cin >> tf[len][0] >> tf[len][1]) {
        len++;
    }

    if (bfs()) {
        cout << ans;
    } else {
        cout << "NO ANSWER!";
    }

    return 0;
}


 