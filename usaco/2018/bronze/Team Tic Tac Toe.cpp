// the main idea is to realize that the same team can win more than once which took me a long time to realize, you can do a better solution
#include <bits/stdc++.h>
using namespace std;
bool are_same(char a, char b, char c)
{
    return a == b && b == c;
}
pair<char, char> get_new_pair(char a, char b, char c){
    if (a == c){
        return {a, b};
    }
    return {a, c};
}
int two_win(vector<vector<char>>& v2d)
{
    set<pair<char, char>> myset;
    int cnt = 0;
    // check if two and only two out of three characters match diagonally
    if ((v2d[1][1] == v2d[0][0] || v2d[1][1] == v2d[2][2] ||
    v2d[0][0] == v2d[2][2]) && !are_same(v2d[0][0], v2d[1][1], v2d[2][2])){
        cnt++;
        pair<char, char> new_pair = get_new_pair(v2d[0][0], v2d[1][1], v2d[2][2]);
        myset.insert(new_pair);
        swap(new_pair.first, new_pair.second);
        myset.insert(new_pair);
    }
    if ((v2d[1][1] == v2d[0][2] || v2d[1][1] == v2d[2][0] ||
    v2d[0][2] == v2d[2][0]) && !are_same(v2d[0][2], v2d[1][1], v2d[2][2])){
        if (myset.find(get_new_pair(v2d[0][2], v2d[1][1], v2d[2][0])) == myset.end()){
            cnt++;
            pair<char, char> new_pair = get_new_pair(v2d[0][2], v2d[1][1], v2d[2][0]);
            myset.insert(new_pair);
            swap(new_pair.first, new_pair.second);
            myset.insert(new_pair);
        }
    }
    for (int i = 0; i < 3; i++){
        if ((v2d[i][0] == v2d[i][1] || v2d[i][1] == v2d[i][2] ||
        v2d[i][0] == v2d[i][2]) && !are_same(v2d[i][0], v2d[i][1], v2d[i][2])){
            if (myset.find(get_new_pair(v2d[i][0], v2d[i][1], v2d[i][2])) == myset.end()){
                pair<char, char> new_pair = get_new_pair(v2d[i][0], v2d[i][1], v2d[i][2]);
                myset.insert(new_pair);
                swap(new_pair.first, new_pair.second);
                myset.insert(new_pair);
                cnt++;
            }
        }
    }
    for (int i = 0; i < 3; i++){
        if ((v2d[0][i] == v2d[1][i] || v2d[1][i] == v2d[2][i] ||
        v2d[0][i] == v2d[2][i]) && !are_same(v2d[0][i], v2d[1][i], v2d[2][i])){
            if (myset.find(get_new_pair(v2d[0][i], v2d[1][i], v2d[2][i])) == myset.end()){
                pair<char, char> new_pair = get_new_pair(v2d[0][i], v2d[1][i], v2d[2][i]);
                myset.insert(new_pair);
                swap(new_pair.first, new_pair.second);
                myset.insert(new_pair);
                cnt++;
            }
        }
    }
    return cnt;
}
int tri_win(vector<vector<char>>& v2d)
{
    unordered_set<char> myset;
    int cnt = 0;
    char ch = v2d[1][1];
    if (v2d[0][0] == ch && v2d[2][2] == ch){
        myset.insert(ch);
        cnt++;
    }
    if (v2d[0][2] == ch && v2d[2][0] == ch && myset.find(ch) == myset.end()){
        myset.insert(ch);
        cnt++;
    }
    for (int i = 0; i < 3; i++){
        ch = v2d[i][0];
        if (ch == v2d[i][1] && ch == v2d[i][2] && myset.find(ch) == myset.end()){
            myset.insert(ch);
            cnt++;
        }
    }
    for (int i = 0; i < 3; i++){
        ch = v2d[0][i];
        if (ch == v2d[1][i] && ch == v2d[2][i] && myset.find(ch) == myset.end()){
            myset.insert(ch);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    //freopen("tttt.in", "r", stdin);
    //freopen("tttt.out", "w", stdout);
    vector<vector<char>> v2d(3, vector<char>('0', 0));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> v2d[i][j];
        }
    }
    int cnt1 = tri_win(v2d);
    int cnt2 = two_win(v2d);
    cout << cnt1 << endl << cnt2 << endl;
    return 0;
}
