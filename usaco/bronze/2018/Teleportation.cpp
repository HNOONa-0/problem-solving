#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int pos1 = min(a, b), pos2 = max(a, b),
    x = min(c, d), y = max(c, d);
    int direct_hauling = pos2 - pos1;
    int teleport_hauling = abs(pos1 - x) + abs(pos2 - y);
    cout << min(direct_hauling, teleport_hauling);
}
