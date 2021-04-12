#include <stdio.h>
#include <iostream>
using namespace std;
struct rect
{
    int x1, y1, x2, y2, h, w;
};
int main()
{
    // freopen ("billboard.in","r",stdin);
    // freopen ("billboard.out","w",stdout);
    rect r1, r2;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    r1.w = r1.x2 - r1.x1, r1.h = r1.y2 - r1.y1;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    //r1.x1 <= r2.x1 + r2.x2 - r2.x1 && r2.x1 <= r1.x1 + r1.x2 - r1.x1 &&
    //r1.y1 <= r2.y1 + r2.y2 - r2.y1 && r1.x1 <= r2.y1 + r2.y2 - r2.y1
    if
    (
        r1.x1 <= r2.x2 && r2.x1 <= r1.x2 &&
        r1.y1 <= r2.y2 && r2.y1 <= r1.y2
    )
    {
        rect r3;
        r3.x1 = max(r1.x1, r2.x1), r3.y1 = max(r1.y1, r2.y1),
        r3.x2 = min(r1.x2, r2.x2), r3.y2 = min(r1.y2, r2.y2);
        int area_of_intersection = (r3.x2 - r3.x1) * (r3.y2 - r3.y1);
        if (area_of_intersection == r1.h * r1.w)
        {
            cout << 0 << endl;
        }
        else if (area_of_intersection % r1.h == 0 ^ area_of_intersection % r1.w == 0)
        {
            cout << (r1.h * r1.w - area_of_intersection) << endl;
        }
        else
        {
            cout << (r1.h * r1.w) << endl;
        }
    }
    else
    {
        cout << (r1.h * r1.w);
    }
    return 0;
}
