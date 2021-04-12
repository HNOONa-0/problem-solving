#include <iostream>
using namespace std;
struct rect
{
    unsigned long long x1, y1, x2, y2;
};
rect compute_intersection(rect r1, rect r2)
{
    if (!(r1.x1 <= r2.x2 && r2.x1 <= r1.x2 &&
    r1.y1 <= r2.y2 && r2.y1 <= r1.y2)){
        return {0, 0, 0, 0};
    }
    return {
        max(r1.x1, r2.x1),
        max(r1.y1, r2.y1),
        min(r1.x2, r2.x2),
        min(r1.y2, r2.y2),
    };
}
unsigned long long acalc(rect r)
{
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}
int main()
{
    rect r1, r2, r3;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    cin >> r3.x1 >> r3.y1 >> r3.x2 >> r3.y2;
 
    rect intersection_1 = compute_intersection(r1, r2), 
    intersection_2 = compute_intersection(r1, r3),
    intersection_3 = compute_intersection(intersection_1, intersection_2);
 
    unsigned long long white_area = acalc(r1);
    unsigned long long area_covered = acalc(intersection_1) 
    + acalc(intersection_2) - acalc(intersection_3);
    if (area_covered >= white_area)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
