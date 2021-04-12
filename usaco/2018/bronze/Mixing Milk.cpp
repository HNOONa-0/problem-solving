#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    // freopen ("mixmilk.in","r",stdin);
    // freopen ("mixmilk.out","w",stdout);
    int milks[3], cap[3];
    cin >> cap[0] >> milks[0];
    cin >> cap[1] >> milks[1];
    cin >> cap[2] >> milks[2];
    for (int i = 0; i < 100; i++){
        if (milks[i % 3] + milks[(i + 1) % 3] >= cap[(i + 1) % 3]){
            milks[i % 3] = milks[i % 3] - (cap[(i + 1) % 3] - milks[(i + 1) % 3]),
            milks[(i + 1) % 3] = cap[(i + 1) % 3];
        }else{
            milks[(i + 1) % 3] += milks[i % 3];
            milks[i % 3] = 0;
        }
    }
    cout << milks[0] << endl << milks[1] << endl << milks[2] << endl;
    return 0;
}
