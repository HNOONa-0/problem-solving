#include <iostream>
using namespace std;
int main()
{
    // freopen ("paint.in","r",stdin);
    // freopen ("paint.out","w",stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a <= d && c <= b ? cout << max(b, d) - min(a, c) : cout << b - a + d - c;
}
 
 
