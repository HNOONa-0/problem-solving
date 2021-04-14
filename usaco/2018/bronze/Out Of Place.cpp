//freopen("socdist1.in", "r", stdin);
//freopen("socdist1.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("outofplace.in", "r", stdin);
    //freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vec1(n), vec2(n);
    for (int i = 0; i < n; i++){
        cin >> vec1[i];
        vec2[i] = vec1[i];
    }
 
    int swap_cnt = -1;
    sort(vec2.begin(), vec2.end());
 
    for (int i = 0; i < n; i++){
        if (vec1[i] != vec2[i]){
            swap_cnt++;
        }
    }
    swap_cnt == -1 ? cout << 0 : cout << swap_cnt;
    return 0;
}
