#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
#define pi 3.141592653589793
#define e 2.718281828459045
using namespace std;
struct mypoint{
    ll x, y;
};
void find2v(vector<mypoint>& v, mypoint& v1, mypoint& v2);
ll calculate_m(vector<mypoint>& v, ll x, ll y, ll best_m, mypoint& v1, mypoint& v2);
void populate_v(set<ll>& myset, vector<ll>& myvector);

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ll n, b;
    cin >> n >> b;
    vector<mypoint> v(n);
    set<ll> different_x, different_y;
    for (int i = 0; i < n; i++){
        cin >> v[i].x;
        cin >> v[i].y;
        different_x.insert(v[i].x);
        different_y.insert(v[i].y);
    }
    if (different_y.size() == 1 || different_x.size() == 1){
        cout << n / 2;
        return 0;
    }

    mypoint v1{99999, 9999}, v2{-9999, -9999};
    ll best_m = n;
    find2v(v, v1, v2);

    vector<ll> possible_y_vec, possible_x_vec;
    populate_v(different_y, possible_y_vec);
    populate_v(different_x, possible_x_vec);

    for (int i = 0; i < possible_x_vec.size(); i++){
        for (int j = 0; j < possible_x_vec.size(); j++){
            ll current_m = calculate_m(v, possible_x_vec[i], possible_y_vec[j], best_m, v1, v2);
            best_m = min(best_m, current_m);
        }
    }
    cout << best_m;

}

ll calculate_m(vector<mypoint>& v, ll x, ll y, ll best_m, mypoint& v1, mypoint& v2){
    ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (int i = 0; i < v.size(); i++){
        //q1
        if (v[i].x > x && v[i].x <= v2.x
        && v[i].y > y && v[i].y <= v2.y){
            q1++;
            // now q2
        }else if (v[i].x >= v1.x && v[i].x < x
        && v[i].y > y && v[i].y <= v2.y){
            q2++;
            // now a3
        }else if (v[i].x >= v1.x && v[i].x < x
        && v[i].y >= v1.y && v[i].y < y){
            q3++;
            // now q4
        }else if (v[i].x > x && v[i].x <= v2.x
        && v[i].y >= v1.y && v[i].y < y){
            q4++;
        }
    }
    return max(q1, max(q2, max(q3, q4)));
}

void find2v(vector<mypoint>& v, mypoint& v1, mypoint& v2){
    for (int i = 0; i < v.size(); i++){
        v1.x = min(v1.x, v[i].x);
        v1.y = min(v1.y, v[i].y);
        v2.x = max(v2.x, v[i].x);
        v2.y = max(v2.y, v[i].y);
    }
}

void populate_v(set<ll>& myset, vector<ll>& myvector){
    for(auto it1 = myset.begin(); it1 != myset.end(); it1++){
        myvector.push_back((*it1) + 1);
    }
}
