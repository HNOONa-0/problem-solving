#include <bits/stdc++.h>
#define ll long long
using namespace std;
int max_yes_finder(pair<string, set<string>>& a,
pair<string, set<string>>& b)
{
    int cnt = 0;
    for (auto& x : a.second){
        if (b.second.find(x) != b.second.end()){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    //freopen("guess.in", "r", stdin);
    //freopen("guess.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<string, set<string>>> v(n);
    string s, t;
    for (int i = 0, k; i < n; i++){
        cin >> s >> k;
        v[i].first = s;
        for (int j = 0; j < k; j++){
            cin >> t;
            v[i].second.insert(t);
        }
    }
    int max_yes = numeric_limits<int>::min();
    for (int i = 0; i < n; i++){
        for (int j = i + 1, temp; j < n; j++){
            temp = max_yes_finder(v[i], v[j]);
            if (temp > max_yes){
                max_yes = temp;
            }
        }
    }
    cout << max_yes + 1 << endl;
}
