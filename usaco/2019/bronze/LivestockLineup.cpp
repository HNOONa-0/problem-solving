//freopen("socdist1.in", "r", stdin);
//freopen("socdist1.out", "w", stdout);
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
string getname(string& s, int dir){
    string t;
    for (int i = dir ? s.size() - 1 : 0; s[i] != ' '; dir ? i-- : i++){
        t.push_back(s[i]);
    }
    if (dir) reverse(t.begin(), t.end());
    return t;
}
bool is_valid_string(string& s, pair<char, char>& a, int index, int n){
    if (n == 0) return true;
    if (n == 2 && (index == 7 || index == 0)) return false;
    if (n == 1 && index == 7 && s[6] == a.first){
        return true;
    }
    if (n == 1 && index == 0 && s[1] == a.first){
        return true;
    }
    if (n == 1 && (s[index - 1] == a.first || s[index + 1] == a.first)){
        return true;
    }
    if (n == 2 && ( (s[index - 1] == a.first && s[index + 1] == a.second) ||
    (s[index - 1] == a.second && s[index + 1] == a.first)) ){
        return true;
    }
    return false;
}
int two_or_one(pair<char, char>& a){
    if (!a.first) return 0;
    if (a.second) return 2;
    return 1;
}
int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    unordered_map<string, char> names{
        {"Beatrice",'1'},
        {"Belinda",'2'},
        {"Bella",'3'},
        {"Bessie",'4'},
        {"Betsy",'5'},
        {"Blue",'6'},
        {"Buttercup",'7'},
        {"Sue",'8'}
    };
    vector<string>v(8);
    for (auto& x : names){
        v[x.second - 49] = x.first;
    }
    int n;
    cin >> n;
    cin.ignore();
    string s, n1, n2;
    map<char, pair<char, char> > mymap;

    for (int i = 0; i < n; i++){
        getline(cin, s);
        n1 = getname(s, 0);
        n2 = getname(s, 1);

        char val1 = min(names[n1], names[n2]), val2 = max(names[n1], names[n2]);
        if (mymap.find(val1) == mymap.end()){
            mymap[val1].first = val2;
        }else{
            mymap[val1].second = val2;
        }
    }
    string p = "12345678";
    vector<string> candidates;
    for (int i = 0; i < 40320; i++){
        bool new_string = true;
        for (int j = 0; j < 8; j++){
            int test = two_or_one(mymap[p[j]]);
            new_string = is_valid_string(p, mymap[p[j]], j, test);
            if (!new_string){
                break;
            }
        }
        if (new_string){
            candidates.push_back(p);
        }
        next_permutation(p.begin(), p.end());
    }
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < 8; i++){
        cout << v[candidates[0][i] - 49] << endl;
    }
    return 0;
}
