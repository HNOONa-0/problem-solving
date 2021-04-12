// vector of boolean datatype is bad practice, use deque/other data structures instead, dont do what i did here

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x < 4)
    {
        cout << "YES";
        return 0;
    }
    vector<bool> v(x + 1, true);
    v[0] = v[1] = false;
    for (int i = 2; i * i <= x; i++)
    {
        if (v[i])
        {
            for (int j = i; j * i <= x; j++)
            {
                v[j * i] = false;
            }
        }
    }
    v[x] ? cout << "YES" : cout << "NO";
}
