#include <iostream>
using namespace std;
int main()
{
    // freopen ("square.in","r",stdin);
    // freopen ("square.out","w",stdout);
    int lowest_x, lowest_y, heighst_x, heighst_y,
    r1_x1, r1_y1, r1_x2, r1_y2,
    r2_x1, r2_y1, r2_x2, r2_y2;
    cin >> r1_x1 >> r1_y1 >> r1_x2 >> r1_y2;
    cin >> r2_x1 >> r2_y1 >> r2_x2 >> r2_y2;
    lowest_x = min(r1_x1, r2_x1), lowest_y = min(r1_y1, r2_y1);
    heighst_x = max(r1_x2, r2_x2), heighst_y = max(r1_y2, r2_y2);
    int side = max(heighst_x - lowest_x, heighst_y - lowest_y);
    cout << side * side;
    return 0;
}
 
