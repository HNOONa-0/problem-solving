#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    // freopen("shell.in", "r", stdin);
    // freopen("shell.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> guesses(n);
    vector<pair<int, int>> swaps(n);
    for (int i = 0, a, b, g; i < n; i++){
        cin >> a >> b >> g;
        guesses[i] = g - 1;
        swaps[i] = {a - 1, b - 1};
    }
    int max_guesses = -999999;
    vector<int> shells{1, 2, 3};
    for (int i = 0; i < 3; i++){
        int current_shell = shells[i], cnt = 0;
        for (int j = 0; j < n; j++){
            swap(shells[swaps[j].first], shells[swaps[j].second]);
            if (shells[guesses[j]] == current_shell){
                cnt++;
            }
        }
        max_guesses = max(max_guesses, cnt);
        shells.assign({1, 2, 3});
    }
    cout << max_guesses << endl;
}
