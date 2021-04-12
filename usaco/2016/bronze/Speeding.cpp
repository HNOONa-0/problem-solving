#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // freopen ("square.in","r",stdin);
    // freopen ("square.out","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<int> v(101);
    for (int i = 0, j = 0, read1, read2, read1_copy = 0; i < n; i++)
    {
        cin >> read1 >> read2;
        read1 += read1_copy;
        while (j <= read1)
        {
            v[j] = read2;
            j++;
        }
        read1_copy = read1;
    }
    int speed_limit = 0;
    for (int i = 0, j = 0, read1, read2, read1_copy = 0; i < m; i++)
    {
        cin >> read1 >> read2;
        read1 += read1_copy;
        while (j <= read1)
        {
            speed_limit = max(speed_limit, read2 - v[j++]);
        }
        read1_copy = read1;
    }
    cout << speed_limit << endl;
}
