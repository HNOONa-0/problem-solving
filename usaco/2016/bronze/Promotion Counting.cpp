#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //freopen("promote.in", "r", stdin);
    //freopen("promote.out", "w", stdout);
    vector<int> before(4), after(4), promotions(3, 0);
    for (int i = 0; i < 4; i++){
        cin >> before[i] >> after[i];
    }
    promotions[0] = promotions[1] = promotions[2] = after[3] - before[3];
    promotions[0] += after[2] - before[2], promotions[1] += after[2] - before[2];
    promotions[0] += after[1] - before[1];
    for (auto& x : promotions){
        cout << x << endl;
    }
    return 0;
}
