//freopen("socdist1.in", "r", stdin);
//freopen("socdist1.out", "w", stdout);
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void possible_pairs(vector<int>& v, set<pair<int, int>>& myset);
int main()
{
    //freopen("gymnastics.in", "r", stdin);
    //freopen("gymnastics.out", "w", stdout);
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    k--;
    set<pair<int, int>> myset;
    possible_pairs(v, myset);
 
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> v[j];
        }
        for (int j = 0; j < n; j++)
        {
            for (int l = j + 1; l < n; l++){
                if (myset.find(pair<int, int>(v[l], v[j])) != myset.end()){
                    myset.erase(pair<int, int>(v[l], v[j]));
                }
            }
        }
    }
    cout << myset.size();
    return 0;
}
void possible_pairs(vector<int>& v, set<pair<int, int>>& myset){
    for (int i = 0, n = v.size(); i < n; i++){
        for (int j = i + 1; j < n; j++){
            myset.insert(pair<int, int>(v[i], v[j]));
        }
    }
}
 
