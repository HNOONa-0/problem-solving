#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    string s;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    v.push_back("");
    for (int i = 0, ltrs_cnt = 0; i < n; i++){
        ltrs_cnt += v[i].size();
        if (ltrs_cnt <= k){
            cout << v[i];
        }
        else{
            cout << endl << v[i];
            ltrs_cnt = v[i].size();
        }
        if (ltrs_cnt + v[i + 1].size() <= k && i != n - 1){
            cout << " ";
        }
    }
}
