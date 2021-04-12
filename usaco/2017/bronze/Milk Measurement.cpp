#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
int convert_to_n(string&);
int main()
{
    // freopen ("measurement.in","r",stdin);
    // freopen ("measurement.out","w",stdout);
    int n;
    cin >> n;
    unordered_map<string, int> names = {
        {"Bessie", 0},
        {"Mildred", 1},
        {"Elsie", 2}
    };
    map<int, vector<pair<int, int>>> mymap;
    string s, t;
    for (int i = 0, day, val; i < n; i++){
        cin >> day >> s >> t;
        val = convert_to_n(t);
        mymap[day].push_back({names[s], val});
    }
    int milks[3] = {7, 7, 7}, display_cnt = 0;
    int before[] = {0, 0, 0}, after[3];
    for (auto& y : mymap)
    {
        for (auto& x : y.second){
            milks[x.first] += x.second;
        }
        int max_n = max(max(milks[0], milks[1]), milks[2]);
        for (int i = 0; i < 3; i++){
            if (milks[i] == max_n){
                after[i] = 1;
            }else{
                after[i] = 0;
            }
        }
        for (int i = 0; i < 3; i++){
            if (after[i] != before[i]){
                display_cnt++;
                break;
            }
        }
        for (int i = 0; i < 3; i++){before[i] = after[i];}
    }
    cout << display_cnt;
}
int convert_to_n(string& s){
    bool is_neg = s[0] == '-' ? true : false;
    int n = s.size(), x = 0;
    for (int i = 1; i < n; i++){
        int next_d = s[i] - 48;
        x = x * 10 + next_d;
    }
    if (is_neg) return -x;
    return x;
}
