// there is one test case where time limit is exceeded
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mymap[v[i]] = i;
    }
    for (int i = 0; i < n; i++){
        if (mymap.find(x - v[i]) != mymap.end() && i != mymap[x - v[i]]){
            cout << max(mymap[x - v[i]], i) + 1 << " " << min(i, mymap[x - v[i]]) + 1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
