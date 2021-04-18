#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
using namespace std;
struct mypoint{
    ll x, y;
};
int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    vector<mypoint> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y;
    }
    ll maxbxd = THE_MIN;
    for (int i = 0; i < n; i++){
        ll temp_width = 0, temp_height = 0;
        for (int j = i + 1; j % n != i; j++){
            if (v[j % n].x == v[i].x && abs(v[i].y - v[j % n].y) > temp_height)
                temp_height = abs(v[i].y - v[j % n].y);
            if (v[j % n].y == v[i].y && abs(v[i].x - v[j % n].x) > temp_width)
                temp_width = abs(v[i].x - v[j % n].x);
        }
        if (maxbxd < temp_width * temp_height){
            maxbxd = temp_width * temp_height;
        }
    }
    cout << maxbxd;
}
