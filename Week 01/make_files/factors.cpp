#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number : ";
    cin >> n;
    cout << "Factors : ";
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}