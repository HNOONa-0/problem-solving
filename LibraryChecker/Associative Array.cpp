#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<unsigned long long, unsigned long long> mymap;
    unsigned long long q, read1, read2, read3;
    cin >> q;
    for (unsigned long long i = 0; i < q; i++){
        cin >> read1;
        if (read1){
            cin >> read2;
            if (mymap.find(read2) != mymap.end()){
                cout << mymap[read2] << endl;
            }else{
                cout << 0 << endl;
            }
        }
        else{
            cin >> read2 >> read3;
            mymap[read2] = read3;
        }
    }
}
