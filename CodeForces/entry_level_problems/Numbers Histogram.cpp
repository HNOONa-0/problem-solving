#include <iostream>
using namespace std;
int main()
{
    char ch;
    int x_i, n;
    cin >> ch;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x_i;
        for (int j = 0; j < x_i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
    
