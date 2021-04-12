#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // freopen ("cbarn.in","r",stdin);
    // freopen ("cbarn.out","w",stdout);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long min_distance = 100000000;
    for (int i = 0; i < n; i++){
        long long counter = 0;
        for (int j = i + 1, m = 1; j % n != i; j++, m++){
            counter += m * v[j % n];
        }
        min_distance = min(min_distance, counter);
    }
    cout << min_distance;
}
