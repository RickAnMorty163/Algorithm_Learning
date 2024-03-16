#include <iostream>
using namespace std;

const int N = 100010;

int l[N], r[N], value[N], index; // l[N]左指针,r[N]右指针,value[N]节点的值

void init()
{
    // 下标0：左端点 下标1：右端点
    r[0] = 1, l[1] = 0; // 初始状态没有元素时 0 <——> 1
    index = 2;
}

// 在第k个点后边插入x
void insert(int k, int x)
{
    value[index] = x;

    // 链接index
    r[index] = r[k]; // 插入元素的r指针等于k的r指针
    l[index] = k;    // 插入元素的l指针指向k

    // 调整index左右节点的指针
    r[k] = index;
    l[r[index]] = index;
    index++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

signed main()
{
    ios::sync_with_stdio(0);

    int m;
    cin >> m;

    init();

    while (m--)
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "L")
        {
            cin >> x;
            insert(0, x); //在左端点0后插入
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x); // l[1]找到最后一个节点，在其后插入
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);//初始从2开始，保证k=1时，从2开始删除
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << value[i] << " ";
    cout << "\n";
    return 0;
}