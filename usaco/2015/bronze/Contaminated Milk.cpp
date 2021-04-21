#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<unsigned long long>::max()
#define THE_MIN numeric_limits<long long>::min()
#define pi 3.141592653589793
#define e 2.718281828459045
using namespace std;
struct mypoint{
    ll x, y;
};
int main()
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    unordered_map<int, set<pair<int, int> > > mymap;
    for (int i = 0,p,m,t; i < d; i++){
        cin >> p >> m >> t;
        mymap[p].insert({m, t});
    }

    vector<pair<int, int> > sick_ppl(s);
    for (int i = 0,p,t; i < s; i++){
        cin >> sick_ppl[i].first >> sick_ppl[i].second;
    }

    map<int, int> suspects;
    for (int i = 0; i < s; i++){
        for (auto& [key, val] : mymap){
            if (sick_ppl[i].first == key){
                set<int> unique_milks;
                for (auto& [key2, val2] : val){
                    if (val2 < sick_ppl[i].second && unique_milks.find(key2) == unique_milks.end()){
                        suspects[key2]++;
                        unique_milks.insert(key2);
                    }
                }
            }
        }
    }
    vector<int> true_suspects;
    for (auto& [key, val] : suspects){
        if (val == s){
            true_suspects.push_back(key);
        }
    }
    int sick_indivduals = 0;
    for (int i = 0; i < true_suspects.size(); i++){
        int temp = 0;
        for (auto& [key, val] : mymap){
            for (auto& [key2, val2] : val){
                if (key2 == true_suspects[i]){
                    temp++;
                    break;
                }
            }
        }
        sick_indivduals = max(sick_indivduals, temp);
    }
    cout << sick_indivduals;
    return 0;
}
