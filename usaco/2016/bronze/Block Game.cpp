#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // freopen("blocks.in", "r", stdin);
    // freopen("blocks.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> asci(26, 0), asci1(26, 0), asci2(26, 0), asci3(26, 0);
    string s, t;
    for (int i = 0; i < n; i++){
        cin >> s >> t;
        for (int i = 0; i < s.size(); i++){
            asci1[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++){
            asci2[t[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++){
            asci[i] += max(asci1[i], asci2[i]);
        }
        asci1 = asci2 = asci3;
    }
    for (int i = 0; i < 26; i++) cout << asci[i] << endl;
    return 0;
}
