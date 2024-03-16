#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= num / i; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        if (isPrime(x))
            cout << "Yes"
                 << "\n";
        else
            cout << "No"
                 << "\n";
    }

    return 0;
}