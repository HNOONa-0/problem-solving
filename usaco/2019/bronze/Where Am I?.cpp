#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //freopen("whereami.in", "r", stdin);
    //freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    char chs[n] = {0};
    string s;
    cin >> s;
    int k = 1, k_cpy = -1;
    set <string> myset;
    while (k != k_cpy)
    {
        k_cpy = k;
        for (int i = 0; i < n; i++){
            if (i + k > n) break;
            for (int j = 0; j < k; j++){
                chs[j] = s[i + j];
            }
            if (myset.find(chs) == myset.end()){
                myset.insert(chs);
            }else{
                k++;
                break;
            }
        }
        myset.clear();
    }
    cout << k;
}
