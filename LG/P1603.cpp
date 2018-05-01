#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-29
 *  @Time: 17:25
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define all(x) begin(x),end(x)
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 500
#define maxm 20005
lli l, m, n, minn, maxx, r, q;
vector<string> data;

void add(string &x) {
    if (x == "one")data.push_back("01");
    else if (x == "two")data.push_back("04");
    else if (x == "three")data.push_back("09");
    else if (x == "four")data.push_back("16");
    else if (x == "five")data.push_back("25");
    else if (x == "six")data.push_back("36");
    else if (x == "seven")data.push_back("49");
    else if (x == "eight")data.push_back("64");
    else if (x == "nine")data.push_back("81");
    else if (x == "ten")data.push_back("00");
    else if (x == "eleven")data.push_back("21");
    else if (x == "twelve")data.push_back("44");
    else if (x == "thirteen")data.push_back("69");
    else if (x == "fourteen")data.push_back("96");
    else if (x == "fifteen")data.push_back("25");
    else if (x == "sixteen")data.push_back("56");
    else if (x == "seventeen")data.push_back("89");
    else if (x == "eighteen")data.push_back("24");
    else if (x == "nineteen")data.push_back("61");
    else if (x == "twenty")data.push_back("00");
    else if (x == "a")data.push_back("01");
    else if (x == "both")data.push_back("04");
    else if (x == "another")data.push_back("09");
    else if (x == "first")data.push_back("01");
    else if (x == "second")data.push_back("04");
    else if (x == "third")data.push_back("09");
}

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int P1603() {
    string temp;
    loop(i, 1, 6) {
        cin >> temp;
        add(temp);
    }
    if (data.size() == 0) {
        cout << 0;
        return 0;
    }
    sort(all(data), cmp);
    string ans = "";
    loop(i, 0, data.size() - 1) {
        ans += data[i];
    }
    int index = 0;
    while (ans[index] == '0' && index < ans.length() - 1) {
        index++;
    }
    loop(i, index, ans.length() - 1) {
        cout << ans[i];
    }

    return 0;
}

 