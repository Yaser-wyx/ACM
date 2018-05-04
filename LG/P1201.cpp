#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-03
 *  @Time: 21:52
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
#define maxn 20
int n, m, r, c;
string names[maxn];
int money[maxn];

int P1201() {
    cin >> n;
    map<string, int> peoples;
    string name;
    mset(money, 0);
    loop3(i, 0, n) {
        cin >> name;
        names[i] = name;
        peoples[name] = i;
    }
    int a, b;
    while (cin >> name) {
        int index = peoples[name];
        cin >> a >> b;
        if (b == 0) {
            continue;
        }
        int every = a / b;
        money[index] -= b * every;
        loop3(i, 0, b) {
            cin >> name;
            index = peoples[name];
            money[index] += every;
        }
    }

    loop3(i, 0, n) {
        cout << names[i] << " " << money[i] << endl;
    }

    return 0;
}

 