#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    cout << "floor " << x << " / " << y << " = " << floor(static_cast<double>(x) / y) << endl;
    cout << "ceil " << x << " / " << y << " = " << ceil(static_cast<double>(x) / y) << endl;
    cout << "round " << x << " / " << y << " = " << round(static_cast<double>(x) / y) << endl;
    return 0;
}
