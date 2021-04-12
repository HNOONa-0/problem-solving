#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;
struct record {
    int ramp, a, b;
};
int main()
{
    // freopen("traffic.in", "r", stdin);
    // freopen("traffic.out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<string, int> mymap{
        {"off", 0},
        {"on", 1},
        {"none", 2},
    };
    string s;
    vector<record> v(n);
    for (int i = 0, read1, read2; i < n; i++){
        cin >> s >> read1 >> read2;
        v[i] = {mymap[s], read1, read2};
    }
    pair<int, int> mile_one(-9999999, 9999999), mile_final = mile_one;
    for (int i = 0; i < n; i++){
        if (v[i].ramp == 0){
            mile_final.first -= v[i].b;
            mile_final.second -= v[i].a;
        }else if (v[i].ramp == 1){
            mile_final.first += v[i].a;
            mile_final.second += v[i].b;
        }else{
            mile_final = {max(mile_final.first, v[i].a),
            min(mile_final.second, v[i].b)};
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if (v[i].ramp == 0){
            mile_one.first += v[i].a;
            mile_one.second += v[i].b;
        }else if (v[i].ramp == 1){
            mile_one.first -= v[i].b;
            mile_one.second -= v[i].a;
        }else{
            mile_one = {max(mile_one.first, v[i].a),
            min(mile_one.second, v[i].b)};
        }
    }
    if (mile_one.first < 0) mile_one.first = 0;
    if (mile_one.second < 0) mile_one.second = 0;
    if (mile_final.first < 0) mile_final.first = 0;
    if (mile_final.second < 0) mile_final.second = 0;
    cout << mile_one.first << " " << mile_one.second << endl;
    cout << mile_final.first << " " << mile_final.second << endl;
    return 0;
}
