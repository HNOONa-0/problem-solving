#include <bits/stdc++.h>
#define ll long long
#define MAXLL numeric_limits<long long>::max()
#define F first
#define S second
#define unmap unordered_map
#define pi 3.141592653589793
using namespace std;
int cnt = 0;
void check(vector<int>& v, vector<int>& right){
    unmap<int, int> atob, btoa;
	for (int i = 0; i < v.size(); i+=2){
		atob[v[i]] = v[i + 1], btoa[v[i + 1]] = v[i];
	}
	for (int i = 0; i < v.size(); i++){
		bool found = true;
		int curWorm = v[i];
		for (int j = 0; j < v.size(); j++){
			if (right[curWorm] < 0){
				found = false;
				break;
			}
			curWorm = atob.find(right[curWorm]) != atob.end() ? atob[right[curWorm]] : btoa[right[curWorm]];
		}
		if (found){
			cnt++;
			break;
		}
	}
}
vector<int> rightToMe(vector<int>& x, vector<int>& y){
	int n = x.size();
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++){
        // whats right to hole i
        for (int j = 0; j < n; j++){
            if (y[i] == y[j] && x[i] > x[j]){
                res[i] = j;
            }
        }
    }
    return res;
}
void makeCombinations(vector<int>& v, vector<int>& seats,
int index, int start, vector<int>& right, vector<int>& x, vector<int>& y){
	if (index == v.size()){
        check(v, right);
	    return;
	}
	for (int i = start; i < v.size(); i++){
		if (seats[i]) continue;
		seats[i] = 1;
		v[index] = i;
		for (int j = i + 1; j < v.size(); j++){
			if (seats[j]) continue;			
			seats[j] = 1;
			v[index + 1] = j;
			makeCombinations(v, seats, index + 2, i + 1, right, x, y);
			seats[j] = 0;
		}
		seats[i] = 0;
	}
}
int main(){
  	freopen("wormhole.in", "r", stdin);
  	freopen("wormhole.out", "w", stdout);
	int n;
	cin >> n;
	assert(n && n % 2 == 0);
	vector<int> x(n, 0);
	vector<int> y(n, 0);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	vector<int> right = rightToMe(x, y), v(n), seats(n);
    makeCombinations(v, seats, 0, 0, right, x, y);
	cout << cnt;
}
