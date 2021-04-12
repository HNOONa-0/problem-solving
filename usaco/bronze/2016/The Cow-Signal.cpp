#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        vector<char> v((s.size() * k) + 1);
        v.back() = '\n';
        for (int i = 0, j = 0; i < s.size(); i++, j+= k)
        {
            for (int l = 0; l < k; l++)
            {
                v[l + j] = s[i];
            }
        }
        for (int o = 0; o < k; o++)
        {
            for (auto& x : v){cout << x;}
        }
    }
    return 0;
}
