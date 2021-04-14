#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    long long least_difference = numeric_limits<int>::max(), sum = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    unsigned sets_possible = pow(2, n);
    for (size_t i = 0; i < sets_possible; i++){
        long long temp_sum = 0;
        for (size_t j = 0; j < n; j++){
            if (i & (1 << j)){
                temp_sum += v[j];
            }
        }
        least_difference = min(least_difference, abs(sum - 2 * temp_sum));
    }
    cout << least_difference;
    return 0;
}
