// there is probably a better way to check cases, you can improve on my solution
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int zero_counter(char* s, int n, bool which_way)
{
    int cnt = 0;
    switch(static_cast<int>(which_way)){
        case 0:
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == '1'){
                return cnt;
            }else{
                cnt++;
            }
        }
        break;
        case 1:
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                return cnt;
            }else{
                cnt++;
            }
        }
        break;
    }
    return cnt;
}
int two_in_same_row(int n, bool which_zeroes){
    switch(static_cast<int>(which_zeroes)){
        case 1:
        return ((n - 2) / 2) + 1;
        case 0:
        return ((n - 2) / 3) + 1;
    }
    throw;
}
int two_in_different_rows(int n, int m, bool which_zeroes){
    switch(static_cast<int>(which_zeroes)){
        case 0:
        return min( ((n - 1) / 2) + 1, ((m - 1) / 2) + 1 );
        case 1:
        if (n == 0){
            return numeric_limits<int>::min();
        }
        return min(n - 1, ((m - 1)/ 2) + 1);
    }
    throw;
}
int main()
{
    //freopen("socdist1.in", "r", stdin);
    //freopen("socdist1.out", "w", stdout);
    int n;
    cin >> n;
    char stalls[n];
    cin >> stalls;
 
    int left_zeroes = zero_counter(stalls, n, true),
    right_zeroes = zero_counter(stalls, n, false);
    if (left_zeroes == n){
        cout << n - 1 << endl;
        return 0;
    }
 
    int cnt = 0, intial_d = numeric_limits<int>::max();
    bool seen_one = false;
    vector<int> v;
 
    for (int i = left_zeroes; i < n - right_zeroes; i++){
        if (stalls[i] == '1'){
            if (seen_one && i != n){
                cout << 1 << endl;
                return 0;
            }
            seen_one = true;
            if (cnt > 0){
                v.push_back(cnt);
                intial_d = min(intial_d, cnt + 1);
                cnt = 0;
            }
        }else{
            cnt++;
            seen_one = false;
        }
    }
    sort(v.begin(), v.end());
    vector<int> potential_new_d;
    if (left_zeroes > 0) potential_new_d.push_back(two_in_same_row(left_zeroes, true));
 
    if (right_zeroes > 0) potential_new_d.push_back(two_in_same_row(right_zeroes, true));
 
    for (int i = v.size() - 1; i >= 0 && i >= static_cast<int>(v.size() - 2); i--){
 
        potential_new_d.push_back(two_in_same_row(v[i], false));
    }
    if (left_zeroes > 0 && right_zeroes > 0)
        potential_new_d.push_back(min(left_zeroes, right_zeroes));
    for (int i = v.size() - 1; i >= 0 && i >= static_cast<int>(v.size()) - 2; i--){
        potential_new_d.push_back(two_in_different_rows(left_zeroes, v[i], true));
 
        potential_new_d.push_back(two_in_different_rows(right_zeroes, v[i], true));
    }
    if (static_cast<int>(v.size()) - 1 >= 0 && static_cast<int>(v.size()) - 2 >= 0)
        potential_new_d.push_back(two_in_different_rows(v[v.size() - 1]
        , v[v.size() - 2], false));
 
    int new_d = numeric_limits<int>::min();
    for (auto& x : potential_new_d){
        new_d = max(new_d, x);
    }
    new_d < intial_d ? cout << new_d << endl : cout << intial_d << endl;
}
