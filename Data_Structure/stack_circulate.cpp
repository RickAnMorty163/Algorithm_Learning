#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <unordered_map>
using namespace std;

stack<int> num;
    stack<char>
        op;

void eval()
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    int c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}
signed main()
{
    ios::sync_with_stdio(0);

    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        int c = str[i];
        if (isdigit(c))
        {
            int x = 0, j = 1;
            while (i < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0'; i = j - 1;
            num.push(x);
        }
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(')
                eval();
            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while(op.size()) eval();
    cout<<num.top()<<endl;
    return 0;
}
