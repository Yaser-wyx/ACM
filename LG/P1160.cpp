#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-22
 *  @Time: 16:17
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 100010
int n, m;
bool del[maxn];

struct node {
    node *pre = NULL;
    int index;
    node *next = NULL;

    void setNext(node &a) {
        if (next != NULL) {
            a.pre = this;
            a.next = this->next;
            this->next->pre = &a;
            this->next = &a;
        } else {
            this->next = &a;
            a.pre = this;
        }
    }

    void setPre(node &a) {
        if (pre != NULL) {
            a.pre = this->pre;
            a.next = this;
            this->pre->next = &a;
            this->pre = &a;
        } else {
            this->pre = &a;
            a.next = this;
        }
    }
} nodes[maxn];

int P1160() {
    nodes[0].next = &nodes[1];
    nodes[1].index = 1;
    nodes[1].pre = &nodes[0];
    scanf("%d", &n);
    int a, b;
    loop(i, 2, n) {
        scanf("%d%d", &a, &b);
        nodes[i].index = i;
        if (b) {
            //右边
            nodes[a].setNext(nodes[i]);
        } else {
            nodes[a].setPre(nodes[i]);
        }
    }
    mset(del, 0);
    scanf("%d", &m);
    int temp;
    loop(i, 1, m) {
        scanf("%d", &temp);
        del[temp] = 1;
    }
    node *next = nodes[0].next;
    loop(i, 1, n) {
        if (!del[next->index]) {
            printf("%d", next->index);
            if (i != n) {
                printf(" ");
            }
        }
        next = next->next;
    }
    return 0;
}