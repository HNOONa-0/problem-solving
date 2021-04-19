// i dont know if there is a better solution than this, i thought about this really hard for about
// 4 hours, this is what i came up with
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
#define pi 3.141592653589793
#define e 2.718281828459045
using namespace std;
void get_input(map<int, int>& m1, map<int, int>& m2);
vector<pair<map<int, int>, map<int, int>>> update_mapv(
    vector<pair<map<int, int>, map<int, int>>>& mapv);
int main()
{
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<pair<map<int, int>, map<int, int>>> mapv;
    map<int, int> m1, m2;
    get_input(m1, m2);

    mapv.push_back(pair<map<int, int>, map<int, int>>({m1, m2}));
    for (int i = 0; i < 4; i++){
        mapv = update_mapv(mapv);
    }
    set<int> myset;
    for (auto& x : mapv){
        auto& map = x.second;
        int sum = 0;
        for (auto& [key, val] : map){
            sum += key * val;
        }
        myset.insert(sum);
    }
    cout << myset.size();
}
vector<pair<map<int, int>, map<int, int>>> update_mapv(
    vector<pair<map<int, int>, map<int, int>>>& mapv)
{
    vector<pair<map<int, int>, map<int, int>>> new_mapv;
    for (auto& x : mapv){
        auto& map1 = x.first, map2 = x.second;
        for (auto& [key, val] : map1){
                if (val != 0){
                    auto temp1 = map1, temp2 = map2;
                    temp2[key]++;
                    temp1[key]--;
                    new_mapv.push_back(pair<map<int, int>, map<int, int>>({temp2, temp1}));
                }
            }
    }
    return new_mapv;
}
void get_input(map<int, int>& m1, map<int, int>& m2){
    for (int i = 0, read; i < 10; i++){
        cin >> read;
        if (m1.find(read) != m1.end()){
            m1[read]++;
        }else{
            m1[read] = 1;
        }
    }
    for (int i = 0, read; i < 10; i++){
        cin >> read;
        if (m2.find(read) != m2.end()){
            m2[read]++;
        }else{
            m2[read] = 1;
        }
    }
}
