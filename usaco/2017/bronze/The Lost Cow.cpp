#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    // freopen ("lostcow.in","r",stdin);
    // freopen ("lostcow.out","w",stdout);
    long long x, y;
    cin >> x >> y;
    if (x == y){
        cout << 0 << endl;
        return 0;
    }
    long long d = 1, current_position = x, next_position, steps = 0;
    if (x > y){
        while (current_position > y){
        next_position = x + d;
        steps += abs(next_position - current_position);
        current_position = next_position;
        d *= -2;
        }
    }
    else{
        while (current_position < y){
            next_position = x + d;
            steps += abs(next_position - current_position);
            current_position = next_position;
            d *= -2;
        }
    }
    cout << steps - abs(current_position - y);
    return 0;
}
