#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    // freopen ("shuffle.in","r",stdin);
    // freopen ("shuffle.out","w",stdout);
    int n;
    cin >> n;
    unordered_map<int, int> mymap;
    for (int i = 0, read; i < n; i++){
        cin >> read;
        mymap[read - 1] = i;
    }
    vector<int> given_id;
    for (int i = 0; i < n; i++){
        long long read;
        cin >> read;
        given_id.push_back(read);
    }
    vector<int> original_id(n, 0);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            int index = mymap[j];
            original_id[index] = given_id[j];
        }
        given_id = original_id;
    }
    for (auto& x : original_id) cout << x << endl;
}
