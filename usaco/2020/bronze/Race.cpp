// i used gaussian formula to decide if i should increase, decrease or remain constant
//freopen("socdist1.in", "r", stdin);
//freopen("socdist1.out", "w", stdout);
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
ll gauss_formula(double n, double x);
 
int main()
{
    //freopen("race.in", "r", stdin);
    //freopen("race.out", "w", stdout);
    ll n, k;
    cin >> k >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < n; i++){
        ll d_left = k, seconds = 0, curr_speed = 0, x = v[i];
        while(d_left > 0){
            if (curr_speed < x){
                curr_speed++;
            }else if (curr_speed >= x){
                ll next_d = d_left - (curr_speed + 1);
                if (gauss_formula(curr_speed, x) <= next_d){
                    curr_speed++;
                }else{
                    ll left_overs = d_left - gauss_formula(curr_speed - 1, x);
                    ll q = left_overs / curr_speed;
                    d_left -= q * curr_speed, seconds += q;
                    curr_speed--;
                    continue;
                }
 
            }
            d_left -= curr_speed;
            seconds++;
        }
        cout << seconds << endl;
    }
    return 0;
}
ll gauss_formula(double n, double x){
    return (n / 2 * (n + 1)) - (x / 2 * (x + 1)) + x;
}
