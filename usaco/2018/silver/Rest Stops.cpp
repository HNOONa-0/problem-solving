#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
using namespace std;
struct mypoint{
    ll x, y;
};
int find_best_index(ll seconds_consumed, ll r_fj, ll r_b, int start,
    vector<ll>& position, vector<ll>& tastiness){

    ll maximum_e = THE_MIN;
    int index_to_return = -1;
    for (int i = start; i < position.size(); i++){
        if (tastiness[i] > maximum_e){
            maximum_e = tastiness[i];
            index_to_return = i;
        }
    }
    return index_to_return;
}
int main()
{
    //freopen("reststops.in", "r", stdin);
    //freopen("reststops.out", "w", stdout);
    ll l, n, r_fj, r_b;
    cin >> l >> n >> r_fj >> r_b;
    vector<ll> position(n), tastiness(n);

    for (int i = 0; i < n; i++){
       cin >> position[i];
       cin >> tastiness[i];
    }

    ll seconds_consumed = 0, total_tastiness = 0;
    for (int i = 0; i < n; i++){
       int index = find_best_index(seconds_consumed, r_fj, r_b, i, position, tastiness);
       total_tastiness += (position[index] * (r_fj - r_b) - seconds_consumed) * tastiness[index];
       seconds_consumed = position[index] * (r_fj - r_b);
       i = index;
    }
    cout << total_tastiness << endl;

}
