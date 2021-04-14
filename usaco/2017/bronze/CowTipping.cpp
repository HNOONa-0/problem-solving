// my idea was that to pick the farthest "1" because we have to turn it into a 0
#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<long long>::max()
#define THE_MIN numeric_limits<long long>::min()
using namespace std;
struct mypoint{
    int x, y;
};
int main()
{
    //freopen("cowtip.in", "r", stdin);
    //freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<char>> v2d(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v2d[i][j];
        }
    }
    int tips_done = 0;
    mypoint p1{-1, -1};
    while (true){
        int cnt = 0, sum_at_point = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (v2d[i][j] == '1'){
                    cnt++;
                    if (i + j > sum_at_point){
                        sum_at_point = i + j;
                        p1 = {i, j};
                    }
                }
            }
        }
        if (!cnt){break;}
        for (int i = 0; i <= p1.x; i++){
            for (int j = 0; j <= p1.y; j++){
                v2d[i][j] == '0' ? v2d[i][j] = '1' : v2d[i][j] = '0';
            }
        }
        tips_done++;
    }
    cout << tips_done << endl;
    return 0;
}
