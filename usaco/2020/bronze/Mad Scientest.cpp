#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
#define pi 3.141592653589793
#define e 2.718281828459045
using namespace std;
struct mypoint{
    ll x, y;
};
void flipper3000(vector<char>& b, int start, int end);
mypoint mismatches(int start, vector<char>& a, vector<char>& b);
int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    vector<char> a(n), b(n);
    for (int i = 0; i < n; i++){cin >> a[i];}
    for (int i = 0; i < n; i++){cin >> b[i];}
    int times_flipped = 0;

    for (int i = 0; i < n; i++){
        if (a[i] == b[i]){
            continue;
        }else{
            auto p = mismatches(i, a, b);
            int temp1 = p.x, temp2 = p.y;
            flipper3000(b, i, i + temp2);
            i = temp1;
            times_flipped++;
        }
    }
    cout << times_flipped;

}

void flipper3000(vector<char>& b, int start, int end){
    for (int i = start; i < end; i++){
        if (b[i] == 'H'){
            b[i] = 'G';
        }else if (b[i] == 'G'){
            b[i] = 'H';
        }
    }
}
mypoint mismatches(int start, vector<char>& a, vector<char>& b){
    int cnt = 0;
    for (int i = start; i < a.size(); i++){
        if (a[i] != b[i]){
            cnt++;
        }else{
            return{i - 1, cnt};
        }
    }
    return{a.size() - 2, cnt};
}
