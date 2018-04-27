#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-27
 *  @Time: 14:53
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
int n, k;
double m;
char ss[300];

int P1012() {
    scanf("%d", &n);
    scanf("%s", ss);
    int len = strlen(ss);
    //第一部分
    loop3(i, 0, len) {
        cout << (" ");
        if (ss[i] == '1' || ss[i] == '4') {
            loop(blank, 1, n) {
                cout << " ";
            }
        } else {
            loop(s, 1, n) {
                cout << "-";
            }

        }
        cout << " ";
        cout << " ";

    }
    cout << "\n";
    loop(i, 1, n) {
        loop3(j, 0, len) {
            if (ss[j] == '1') {
                loop(blank, 1, n + 1) {
                    cout << " ";
                }
                cout << "|";
            } else if (ss[j] == '4' || ss[j] == '8' || ss[j] == '9' || ss[j] == '0') {
                cout << "|";
                loop(blank, 1, n) {
                    cout << " ";
                }
                cout << "|";
            } else if (ss[j] == '2' || ss[j] == '3' || ss[j] == '7') {
                loop(blank, 0, n) {
                    cout << " ";
                }
                cout << "|";
            } else {
                cout << "|";
                loop(blank, 0, n) {
                    cout << " ";
                }
            }

            cout << " ";

        }
        cout << "\n";
    }
    loop3(i, 0, len) {
        if (ss[i] == '1' || ss[i] == '7' || ss[i] == '0') {
            loop(blank, 0, n + 1) {
                cout << " ";
            }
        } else {
            cout << " ";
            loop(s, 1, n) {
                cout << "-";
            }
            cout << " ";
        }

        cout << " ";

    }
    cout << "\n";

    loop(i, 1, n) {
        loop3(j, 0, len) {
            if (ss[j] == '1' || ss[j] == '3' || ss[j] == '4' || ss[j] == '5' || ss[j] == '7' || ss[j] == '9') {
                loop(blank, 0, n) {
                    cout << " ";
                }
                cout << "|";
            } else if (ss[j] == '6' || ss[j] == '8' || ss[j] == '0') {
                cout << "|";
                loop(blank, 1, n) {
                    cout << " ";
                }
                cout << "|";
            } else {
                cout << "|";
                loop(blank, 0, n) {
                    cout << " ";
                }
            }

            cout << " ";

        }
        cout << "\n";
    }
    loop3(i, 0, len) {
        cout << " ";
        if (ss[i] == '1' || ss[i] == '4' || ss[i] == '7') {
            loop(blank, 1, n) {
                cout << " ";
            }
        } else {
            loop(s, 1, n) {
                cout << "-";
            }

        }
        cout << " ";

        cout << " ";

    }
    return 0;
}

 