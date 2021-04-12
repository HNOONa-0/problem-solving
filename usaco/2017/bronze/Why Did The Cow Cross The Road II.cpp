#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    // freopen ("cowqueue.in","r",stdin);
    // freopen ("cowqueue.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    long long starting_clock = 0;
    for (auto& x : v){
        starting_clock = max(x.first, starting_clock);
        starting_clock += x.second;
    }
    cout << starting_clock;
}
