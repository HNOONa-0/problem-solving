#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
using namespace std;
struct mypoint{
    ll x, y;
};
int walk_back(vector<int>& v, int index, int t){
    if (index - t < 0){
        return -1;
    }
    int j, cnt = 0;
    for (j = index - 1; cnt < t; j--, cnt++){
        if (v[j] == -1){
            v[j] = v[j + 1] - 1;
        }else if (v[j] != v[j + 1] - 1){
            return -1;
        }
    }
    return j + 1;
}
int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int j = n - 1; j >= 0; j--){
        if (v[j] > 0){
            j = walk_back(v, j, v[j]);
            if (j == -1){
                cout << -1 << endl;
                return 0;
            }
        }
        else if (v[j] == -1){
            continue;
        }
    }
    v[0] = 0;
    int minus_one_cnt = 0, zero_cnt = 0;
    for (int i = 0; i < n; i++){
        if (!v[i]){
            zero_cnt++;
        }else if (v[i] == -1){
            minus_one_cnt++;
        }
    }
    cout << zero_cnt << " " << zero_cnt + minus_one_cnt;
}
