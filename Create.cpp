#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-03
 *  @Time: 09:42
 *  To change this template use File | Settings | File Templates.
 * 
 */

int main() {
    int T = rand() % 10 + 1;
    for (int yuyu = 0; yuyu < T; ++yuyu) {
        int n = rand() % 15 + 1;
        int m = rand() % 15 + 1;
        int a;
        bool hasst = 0;
        printf("%d %d\n", n, m);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a = rand() % 3;
                while ((!a) && hasst)a = rand() % 3;
                if (a == 1)putchar('#');
                else if (a == 2)putchar('.');
                else {
                    putchar('S');
                    hasst = 1;
                }
            }
            cout << endl;
        }
        if (!hasst) {
            putchar('S');
            hasst = 1;
            for (int j = 1; j < m; ++j) {
                a = rand() % 3;
                while ((!a) && hasst)a = rand() % 3;
                if (a == 1)putchar('#');
                else if (a == 2)putchar('.');
                else {
                    putchar('S');
                    hasst = 1;
                }
            }
            cout << endl;
        } else {
            for (int j = 0; j < m; ++j) {
                a = rand() % 3;
                while ((!a) && hasst)a = rand() % 3;
                if (a == 1)putchar('#');
                else if (a == 2)putchar('.');
                else {
                    putchar('S');
                    hasst = 1;
                }
            }
            cout << endl;
        }
    }
}