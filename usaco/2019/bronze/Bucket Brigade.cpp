#include <iostream>
#include <vector>
using namespace std;
struct Point{
    int x, y;
};
int main()
{
    // freopen ("buckets.in","r",stdin);
    // freopen ("buckets.out","w",stdout);
    Point barn_position, rock_position, lake_position;
    vector<vector<char>> v2d(10, vector<char>(10));
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cin >> v2d[i][j];
            if (v2d[i][j] == 'R'){ rock_position.x = i, rock_position.y = j;}
            if (v2d[i][j] == 'L'){ lake_position.x = i, lake_position.y = j;}
            if (v2d[i][j] == 'B'){ barn_position.x = i, barn_position.y = j;}
        }
    }
    if (barn_position.x == rock_position.x && rock_position.x == lake_position.x){
 
        if (abs(barn_position.y - lake_position.y) > abs(barn_position.y - rock_position.y)){
            cout << abs(barn_position.y - lake_position.y) + 1;
                return 0;
        }
    }
    else if (barn_position.y == rock_position.y && rock_position.y == lake_position.y){
 
        if (abs(barn_position.x - lake_position.x) > abs(barn_position.x - rock_position.x)){
            cout << abs(barn_position.x - lake_position.x) + 1;
                return 0;
        }
    }
    cout << abs(barn_position.x - lake_position.x) +
                abs(barn_position.y - lake_position.y) - 1;
}
