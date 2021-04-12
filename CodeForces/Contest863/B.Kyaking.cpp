// this is a dynamic programming approach with a map cache
#include <bits/stdc++.h>
using namespace std;
#define CACHE_MAP unordered_map<int, unordered_map<int, int>>
void insert_mycache(CACHE_MAP& my_cache, int k, int i, int result){
    my_cache[k][i] = result;
}
int recA(vector<int>& v, CACHE_MAP& my_cache, int i, int k){
    if (!k) return 0;
    if (i < 0) return 10000;
    if (my_cache.find(k) != my_cache.end() && 
    my_cache[k].find(i) != my_cache[k].end()){
        return my_cache[k][i];
    }
    int r = min(recA(v, my_cache, i - 1, k), recA(v, my_cache, i - 2, k - 1) + v[i]);
    insert_mycache(my_cache, k, i, r);
    return r;
}
int main()
{
    CACHE_MAP my_cache;
    int n;
    cin >> n;
    int k = n - 1; n *= 2;
    vector<int> v(n), result(n - 1);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        result[i] = v[i + 1] - v[i];
    }
    cout << recA(result, my_cache, n - 2, k);
}
