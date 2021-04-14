#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<ll> v(3);
    for (int i = 0; i < 3; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (v[1] - v[0] == 1 && v[2] - v[1] == 1){
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    ll max_moves = 0, min_moves = 0;
    min_moves = v[1] - v[0] == 2 || v[2] - v[1] == 2 ? 1 : 2;
    max_moves = v[1] - v[0] > v[2] - v[1] ? v[1] - v[0]: v[2] - v[1];
    max_moves--;
    cout << min_moves << endl;
    cout << max_moves << endl;
 
}
