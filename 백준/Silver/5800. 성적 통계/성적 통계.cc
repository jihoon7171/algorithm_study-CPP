#include <iostream>
#include <algorithm>
using namespace std;

int classa[100][51];

int main() {
    int a;
    cin >> a;
    for(int i = 0; i < a; i++) {
        int st;
        cin >> st;
        for(int j = 0; j < st; j++) {
            cin >> classa[i][j];
        }
        
       
        sort(classa[i], classa[i] + st, greater<int>());

       
        int big = 0;
        for(int j = 0; j < st - 1; j++) {
            big = max(classa[i][j] - classa[i][j + 1], big);
        }

        
        cout << "Class " << i + 1 << endl;
        cout << "Max " << classa[i][0] << ", Min " << classa[i][st - 1] << ", Largest gap " << big << endl;
    }

    return 0;
}
