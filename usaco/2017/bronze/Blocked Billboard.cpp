#include <iostream>
#include <string>
using namespace std;
struct point{
    int x, y;
};
struct rect{
    point ur, ll;
};
rect compute_intersection(rect& r1, rect& r2){
    if (!(r1.ll.x <= r2.ur.x && r2.ll.x <= r1.ur.x && r1.ll.y <= r2.ur.y && r2.ll.y <= r1.ur.y)){
        return {
            {0, 0}, {0, 0}
        };
    }
    return {
        {max(r1.ll.x, r2.ll.x),
        max(r1.ll.y, r2.ll.y)},
        {min(r1.ur.x, r2.ur.x),
        min(r1.ur.y, r2.ur.y)}
    };
}
int acalc(rect r1){
    return abs(r1.ll.x - r1.ur.x) * abs(r1.ll.y - r1.ur.y);
}
int main()
{
    rect r1, r2, r3;
    cin >> r1.ll.x >> r1.ll.y >> r1.ur.x >> r1.ur.y;
    cin >> r2.ll.x >> r2.ll.y >> r2.ur.x >> r2.ur.y;
    cin >> r3.ll.x >> r3.ll.y >> r3.ur.x >> r3.ur.y;
    int a_of_twoboards = acalc(r1) + acalc(r2),
    a_intersection_1 = acalc(compute_intersection(r1, r3)),
    a_intersection_2 = acalc(compute_intersection(r2, r3));
    cout << a_of_twoboards - (a_intersection_1 + a_intersection_2);
}
