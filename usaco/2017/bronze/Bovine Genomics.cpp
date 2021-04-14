//freopen("socdist1.in", "r", stdin);
//freopen("socdist1.out", "w", stdout);
#include <bits/stdc++.h>
#define ull unsigned long long
void Dna_cnt(char ch, int& a, int& b, int& c, int& d);
bool same_chars(char a, char b);
using namespace std;
int main()
{
    //freopen("cownomics.in", "r", stdin);
    //freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<string> vec1(n), vec2(n);
    for (int i = 0; i < n; i++){
        cin >> vec1[i];
    }
    for (int i = 0; i < n; i++){
        cin >> vec2[i];
    }
    int A_cnt = 0, G_cnt = 0, C_cnt = 0, T_cnt = 0, cnt = 0;
    bool found = true;
    for (int i = 0; i < m; i++){
        A_cnt = G_cnt = C_cnt = T_cnt = 0;
        found = true;
        for (int j = 0; j < n; j++){
            Dna_cnt(vec1[j][i], A_cnt, G_cnt, C_cnt, T_cnt);
        }
        for (int j = 0; j < n; j++){
            if (same_chars('A', vec2[j][i])&& A_cnt){
                found = false;
                break;
            }else if (same_chars('G', vec2[j][i]) && G_cnt){
                found = false;
                break;
            }else if (same_chars('C', vec2[j][i]) && C_cnt){
                found = false;
                break;
            }else if (same_chars('T', vec2[j][i]) && T_cnt){
                found = false;
                break;
            }
        }
        if (found){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
bool same_chars(char a, char b){
    if (a == b){
        return true;
    }
    return false;
}
void Dna_cnt(char ch, int& a, int& b, int& c, int& d){
    switch (ch){
        case 'A': a++;break;
        case 'G': b++;break;
        case 'C': c++;break;
        case 'T': d++;break;
    }
}
