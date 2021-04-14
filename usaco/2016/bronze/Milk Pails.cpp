#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("pails.in", "r", stdin);
    //freopen("pails.out", "w", stdout);
    int x, y, z;
    cin >> x >> y >> z;
    if (z % y == 0 || z % x == 0 || z % (y + x) == 0){
        cout << z << endl;
        return 0;
    }
    int max_possible = numeric_limits<int>::min(), max_xs = (z - (z % x)) / x,
    max_ys = (z - (z % y))  / y;
    for (int i = max_xs; i >= 0; i--){
        for (int j = max_ys; j >= 0; j--){
            int temp = (i * x) + (y * j);
            if (temp <= z && temp > max_possible){
                max_possible = temp;
            }
        }
    }
    cout << max_possible;
}
