#include <iostream>
using namespace std;
long long rec_on_n(long long n){
    if (n){
        if (n == 1){
        cout << 1;
        return 0;
        }else if(n % 2 == 0){
            cout << n << " ";
            return rec_on_n(n / 2);
        }else{
            cout << n << " ";
            return rec_on_n((3 * n) + 1);
        }
    }
}
int main()
{
    long long n;
    cin >> n;
    rec_on_n(n);
 
