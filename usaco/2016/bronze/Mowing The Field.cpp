#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //freopen("mowing.in", "r", stdin);
    //freopen("mowing.out", "w", stdout);
    int n;
    cin >> n;
    int t = 1, min_steps = 1000000;
    map<pair<int, int>, int> mymap;
    pair<int, int> curr_pair(0, 0);
    mymap[curr_pair] = 0;
    char ch;
    for (int i = 0, read; i < n; i++){
        cin >> ch >> read;
        if (ch == 'N'){
            for (int i = 0; i < read; i++){
                curr_pair.second += 1; t++;
                if (mymap.find(curr_pair) != mymap.end()){
                    min_steps = min(min_steps, t - mymap[curr_pair]);
                }
                mymap[curr_pair] = t;
            }
        }else if (ch == 'S'){
            for (int i = 0; i < read; i++){
                curr_pair.second -= 1; t++;
                if (mymap.find(curr_pair) != mymap.end()){
                    min_steps = min(min_steps, t - mymap[curr_pair]);
                }
                mymap[curr_pair] = t;
            }
        }else if (ch == 'E'){
            for (int i = 0; i < read; i++){
                curr_pair.first += 1; t++;
                if (mymap.find(curr_pair) != mymap.end()){
                    min_steps = min(min_steps, t - mymap[curr_pair]);
                }
                mymap[curr_pair] = t;
            }
 
        }else{
            for (int i = 0; i < read; i++){
                curr_pair.first -= 1; t++;
                if (mymap.find(curr_pair) != mymap.end()){
                    min_steps = min(min_steps, t - mymap[curr_pair]);
                }
                mymap[curr_pair] = t;
            }
 
        }
    }
    if (min_steps == 1000000){
        cout << -1 << endl;
        return 0;
    }
    cout << min_steps;
}
