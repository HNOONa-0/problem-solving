#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc_right_bombs(vector<long long>& v, int index, int n){
    int cnt = 0;
    for (int i = index, t = 1; i < n - 1; t++){
        int cnt_cpy = cnt;
        for (int j = i + 1, range = v[i] + t; j < n; j++){
            if (range >= v[j]){
                i++, cnt++;
            }else{
                break;
            }
        }
        if (cnt_cpy == cnt){
            break;
        }
    }
    return cnt;
}
int calc_left_bombs(vector<long long>& v, int index){
    int cnt = 0;
    for (int i  = index, t = 1; i > 0; t++){
        int cnt_cpy = cnt;
        for (int j = i - 1, range = v[i] - t; j >= 0; j--){
            if (range <= v[j]){
                cnt++, i--;
            }else{
                break;
            }
        }
        if (cnt_cpy == cnt){
            break;
        }
    }
    return cnt;
}
int main(){
    // freopen ("angry.in","r",stdin);
    // freopen ("angry.out","w",stdout);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        v[i] = x;
    }
    int max_bombs = numeric_limits<int>::min();
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int left = calc_left_bombs(v, i);
        int right = calc_right_bombs(v, i, n);
        int total = left + right + 1;
        max_bombs = max(max_bombs, left + right + 1);
    }
    cout << max_bombs;
}
