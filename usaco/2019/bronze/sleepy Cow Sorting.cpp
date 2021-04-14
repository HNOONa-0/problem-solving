#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sorted_left(vector<int>& v);
void swap_all(vector<int>& v, int length);
int main()
{
    //freopen("sleepy.in", "r", stdin);
    //freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    int swap_cnt = 0;
    while (true){
        int left_end_length = sorted_left(v);
        if (left_end_length == n) {break;}
        if (v[0] > v[n - 1]){
            //
            swap_all(v, n);
            swap_cnt++;
            continue;
        }
        else if (v[0] < v[n - left_end_length]){
            swap_all(v, n - left_end_length);
            swap_cnt++;
            continue;
        }
        for (int i = n - 1; i >= 1; i--){
            if (v[0] < v[i] && v[0] > v[i - 1]){
                swap_all(v, i);
                break;
            }
        }
        swap_cnt++;
    }
    cout << swap_cnt;
    return 0;
}
 
void swap_all(vector<int>& v, int length){
    for (int i = 0, n = v.size(); i < length - 1; i++){
        swap(v[i], v[i + 1]);
    }
}
int sorted_left(vector<int>& v){
    int cnt = 1;
    for (int n = v.size(), j = n - 1; j >= 1 && v[j] > v[j - 1]; j--){cnt++;}
    return cnt;
}
