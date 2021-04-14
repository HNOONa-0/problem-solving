#include<bits/stdc++.h>
using namespace std;
int fact(int n);
void compute_next_permutation(string& s, int n);
int divisor(string& s, int n);
int main()
{
   string s;
   cin >> s;
   sort(s.begin(), s.end());
   int n = s.size();
   int permutations = fact(n);
   int k = permutations / divisor(s, n);
   cout << k << endl;
 
   set<string> myset;
   for (int i = 0; i < permutations; i++){
       if (myset.find(s) == myset.end()){
           cout << s << endl;
       }
       myset.insert(s);
       compute_next_permutation(s, n);
   }
}
void compute_next_permutation(string& s, int n)
{
    int k = n - 1, index_to_replace = -1;
    for (int i = n - 1; i >= 1 && s[i] <= s[i - 1]; i--){k--;}
    k--;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] > s[k]){
            index_to_replace = i;
            break;
        }
    }
    if (k < 0) return;
    swap(s[k], s[index_to_replace]);
    reverse(s.begin() + k+ 1, s.end());
}
int divisor(string& s, int n)
{
    vector<int> v(26, 0);
    for (int i = 0; i < n; i++){
        v[s[i] - 97]++;
    }
    int cnt = 1;
    for (int i = 0; i < 26; i++){
        cnt *= fact(v[i]);
    }
    return cnt;
}
int fact(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * fact(n - 1);
}
