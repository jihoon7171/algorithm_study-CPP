#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;

    vector<vector<int>> newa(h + x + 1, vector<int>(w + y + 1));
    vector<vector<int>> answer(h + 1, vector<int>(w + 1));


    for (int i = 1; i <= h + x; i++) {
        for (int j = 1; j <= w + y; j++) {
            cin >> newa[i][j];
        }
    }


    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i > x && j > y) {
               
                answer[i][j] = newa[i][j] - answer[i - x][j - y];
            } else {
               
                answer[i][j] = newa[i][j];
            }
        }
    }


    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
