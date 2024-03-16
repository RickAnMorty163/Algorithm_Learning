#include<iostream>
#include<vector>

using namespace std;

void insert(vector<vector<int>> &b, int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;//(x1,y1)右下角所有元素加c
    b[x2 + 1][y1] -= c;//(x2+1,y1)右下角所有元素减c,抵消(x1,y1)+c的影响
    b[x1][y2 + 1] -= c;//(x1,y2+1)右上角所有元素减c,抵消(x1,y1)+c的影响
    b[x2 + 1][y2 + 1] += c;//补偿2,3操作的公共部分
}

signed main() {
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    vector<vector<int>> b(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            insert(b, i, j, i, j, a[i][j]);//类似一维差分数组的构造方式
        }


    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(b, x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];//还原为原始矩阵(前缀和)
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}