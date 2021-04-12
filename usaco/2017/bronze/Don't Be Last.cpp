#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;
bool compareab(pair<int, int> a, pair<int, int> b)
{
       return a.second < b.second;
}
int main()
{
    // freopen("notlast.in", "r", stdin);
    // freopen("notlast.out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<string, int> name_to_n =
    {
         {"Bessie", 1} , {"Elsie", 3}, {"Daisy", 2}, {"Gertie", 4}, {"Annabelle", 0}, {"Maggie", 6}, {"Henrietta", 5}
    };
    unordered_map<int, string> n_to_name =
    {
        {6,"Maggie"} , {0,"Annabelle"} , {4,"Gertie"} , {2,"Daisy"} , {5,"Henrietta"} , {3,"Elsie"} , {1,"Bessie"}
    };
    vector<pair<int, int>> v(7, pair<int, int>(-1, -1));
    int cnt = 0;
    string s;
    for (int i = 0, read; i < n; i++){
        cin >> s >> read;
        if (v[name_to_n[s]].first != -1){
            v[name_to_n[s]].second += read;
        }else{
            v[name_to_n[s]].first = name_to_n[s];
            v[name_to_n[s]].second = read;
            cnt++;
        }
    }
    sort(v.begin(), v.end(), compareab);
    pair<int, int> cow_with_min;
    for (auto& x : v){
        if (x.second > 0){
            cow_with_min = x;
            break;
        }
    }
    if (cnt < 7){
        for (int i = 0; i < 7; i++){
            if (v[i].first != cow_with_min.first && v[i].second == cow_with_min.second){
                cout << "Tie" << endl;
                return 0;
            }
        }
        cout << n_to_name[cow_with_min.first] << endl;
        return 0;
    }
    for (int i = 0; i < 7; i++){
        if (v[i].second > cow_with_min.second){
            cout << n_to_name[v[i].first] << endl;
            return 0;
        }
    }
    cout << "Tie" << endl;
}
