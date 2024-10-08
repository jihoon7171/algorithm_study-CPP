#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> cheeze;
vector<vector<bool>> checked;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void check(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    checked.assign(n, vector<bool>(m, false));
    checked[y][x] = true;

    while(!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newx = nowx + dx[i];
            int newy = nowy + dy[i];

            if(newx >= 0 && newx < m && newy >= 0 && newy < n && !checked[newy][newx]) {
                checked[newy][newx] = true;
                
                if(cheeze[newy][newx] == 1) {
                    cheeze[newy][newx] = 2; // 녹을 치즈 표시
                } else if(cheeze[newy][newx] == 0) {
                    q.push({newx, newy});
                }
            }
        }
    }
}

bool endcheck() {
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(cheeze[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    cheeze.resize(n, vector<int>(m));
    checked.resize(n, vector<bool>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cheeze[i][j];
        }
    }

    int time = 0, onehour;
    while(true) {
        onehour = 0;
        time++;
        check(0, 0);

        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(cheeze[i][j] == 2) {
                    cheeze[i][j] = 0;
                    onehour++;
                }
            }
        }

        if(endcheck()) {
            break;
        }
    }
    cout << time << "\n" << onehour;
}
