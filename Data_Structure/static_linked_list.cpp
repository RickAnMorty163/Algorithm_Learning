#include<iostream>

using namespace std;

const int N = 100010;

int head, value[N], ptr[N], index;//节点的value和ptr通过数组下标关联,head为头结点下标
//节点 i<->index i
void init() {
    head = -1;//头结点为空
    index = 0;
}

//头插
void pushfront(const int &x) {
    value[index] = x;
    ptr[index] = head;
    head = index++;
}

//插入x到k的后驱节点
void insert(const int &k, const int &x) {
    value[index] = x;
    ptr[index] = ptr[k];//k的后驱节点为index的后驱节点
    ptr[k] = index++;
}

//删除k以后的节点
void remove(const int &k) {
    ptr[k] = ptr[ptr[k]];
}

signed main() {
    ios::sync_with_stdio(0);

    int m;
    cin >> m;

    init();

    while (m--) {
        int k, x;
        char op;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            pushfront(x);
        } else if (op == 'D') {
            cin >> k;
            if (!k) {
                head = ptr[head];//对删除头结点的情况进行特判
            } else {
                remove(k - 1);//注意题目中k从1开始
            }
        } else {
            cin >> k >> x;
            insert(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ptr[i]) cout << value[i] << " ";

}