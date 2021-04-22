// this one is cracked
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define THE_MAX numeric_limits<unsigned long long>::max()
#define THE_MIN numeric_limits<long long>::min()
#define x first
#define y second
#define pi 3.141592653589793
#define e 2.718281828459045
using namespace std;
void flush_v2d(vector<vector<int> >& v2d, int row){
    for (int i = 0; i < 8; i++){
        v2d[row][i] = 0;
    }
}
void make_queens(vector<pair<int, int> >& v, vector<int>& v2){
    int index = 0;
    for (int i = 0; i < 8; i++){
        v[i] = {i, v2[i]};
    }
}
int queen_fight(vector<pair<int, int> >& queens, set<pair<int, int> >& myset){
    for (int i = 0; i < 8; i++) {if (myset.find(queens[i]) != myset.end()) return 0;}
    for (int i = 0; i < 8; i++){
        for (int j = i + 1; j < 8; j++){
            if (queens[i].first == queens[j].first){
                return 0;
            }else if (queens[i].second == queens[j].second){
                return 0;
            }else if (abs(queens[i].first - queens[j].first) == abs(queens[i].second - queens[j].second)){
                return 0;
            }
        }
    }
    return 1;
}
int main()
{

    set<pair<int, int> > myset{};
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            char ch;
            cin >> ch;
            if (ch == '*'){
                myset.insert({i, j});
            }
        }
    }
    vector<vector<int> > v2d(8, vector<int>(8, 0));
    vector<int> y_points(8);
    vector<pair<int, int> > queens(8);
    int cnt = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (j != i){
                for (int k = 0; k < 8; k++){
                    if (k != i && k != j){
                        for (int l = 0; l < 8; l++){
                            if (l != i && l != j && l != k){
                                for (int m = 0; m < 8; m++){
                                    if (m != i && m != j && m != k && m != l){
                                        for (int o = 0; o < 8; o++){
                                            if (o != i && o != j && o != k && o != l && o != m){
                                                for (int p = 0; p < 8; p++){
                                                    if (p != i && p != j && p != k && p != l && p != m && p != o){
                                                        for (int q = 0; q < 8; q++){
                                                            if (q != i && q != j && q != k && q != l && q != m && q != o && q != p){
                                                                y_points[0] = i, y_points[1] = j, y_points[2] = k, y_points[3] = l, y_points[4] = m,
                                                                y_points[5] = o, y_points[6] = p, y_points[7] = q;
                                                                make_queens(queens, y_points);
                                                                cnt += queen_fight(queens, myset);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
