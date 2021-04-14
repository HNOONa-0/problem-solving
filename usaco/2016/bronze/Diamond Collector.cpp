//freopen("socdist1.in", "r", stdin);
//freopen("socdist1.out", "w", stdout);
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int max_d = numeric_limits<int>::min();
 
    for (int i = 0; i < n; i++){
        int cnt = 1;
        for (int j = i + 1; j < n; j++){
            if (abs(v[j] - v[i]) <= k){
                cnt++;
            }
        }
        if (cnt > max_d){
            max_d = cnt;
        }
    }
    cout << max_d;
    return 0;
}
 
