#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
using namespace std;
struct mypair{
    int x, y;
};
int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    vector<mypair> v(26);
    for (int i = 0; i < 52; i++){
        char ch;
        cin >> ch;
        v[static_cast<int>(ch - 65)].x ? v[static_cast<int>(ch - 65)].y = i + 1:
            v[static_cast<int>(ch - 65)].x = i + 1;
    }
    int pair_cnt = 0;
    for (int i = 0; i < 26; i++){
        for (int j = i + 1; j % 26 != i; j++){
            if (v[j % 26].x > v[i].x && v[j % 26].x < v[i].y
            && v[j % 26].y > v[i].y){
                pair_cnt++;
            }
        }
    }
    cout << pair_cnt;

}
