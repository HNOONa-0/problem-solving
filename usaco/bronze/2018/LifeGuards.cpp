#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
#define pi 3.141592653589793
#define e 2.718281828459045
using namespace std;
ll time_wasted(pair<ll, ll>& a, pair<ll, ll>& b);
ll what_time(vector<pair<ll, ll>>& v, int index, ll time_expected);
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    ll time_expected = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        cin >> v[i].second;
        time_expected += (v[i].second - v[i].first);
    }
    ll actual_time = THE_MIN;
    for (int i = 0; i < n; i++){
        ll eq = time_expected - (v[i].second - v[i].first);
        actual_time = max(what_time(v, i, eq), actual_time);
    }
    cout << actual_time;
    
}
ll time_wasted(pair<ll, ll>& a, pair<ll, ll>& b){
    if (a.second < b.first || b.second < a.first) return 0;
    return min(a.second, b.second) - max(a.first, b.first);
}
ll what_time(vector<pair<ll, ll>>& v, int index, ll time_expected){
    int n = v.size();
    ll actual_time = time_expected;
    for (int i = 0; i < n; i++){
        if (i == index) continue;
        for (int j = i + 1; j < n; j++){
            if (j == index) continue;
            actual_time -= time_wasted(v[i], v[j]);
        }
    }
    return actual_time;
}
