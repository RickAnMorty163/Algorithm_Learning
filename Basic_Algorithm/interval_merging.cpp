#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pit;

const int bound = -1e9 - 1;

int n;
vector<pit> terminalPoint;

auto merge(vector<pit> &terminalPoint) {
    vector<pit> res;

    sort(terminalPoint.begin(), terminalPoint.end());//pair排序会优先按照第一个元素排序

    int start = bound, end = bound;//设置start和end初始维护的区间(边界位置)，此区间不会被加入res中
    for (auto t: terminalPoint) {
        if (end < t.first) { //区间没有交集
            if (start != bound) res.push_back({start, end});//将当前区间加入res
            start = t.first, end = t.second;//更新start和end到下一个区间
        } else {//区间有交集，只更新end
            end = max(end, t.second);
        }
    }
    //注意到for循环结束时，terminalPoint中最后一个pair对没有被放入res中
    if (start != bound) res.push_back({start, end});
    terminalPoint = res;//更新terminalPoint
}

signed main() {
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        terminalPoint.push_back({l, r});
    }

    merge(terminalPoint);
    cout << terminalPoint.size();

    return 0;
}