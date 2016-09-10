#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("fib.in", "r", stdin);
    freopen("fib.out", "w", stdout);
    int n, ar[46];
    cin >> n;
    ar[0] = ar[1] = 1;
    for(int i = 2;i <= n;i++)
      ar[i] = ar[i - 1] + ar[i -2];
    cout << ar[n];
    return 0;
}
