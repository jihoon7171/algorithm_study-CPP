#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

int n;
pair<int, int> makemove[8] = {{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0},{1,-1}};

void makecloud(vector<vector<int>>& cloud, vector<vector<int>>& rain, vector<vector<bool>>& check) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!check[i][j] && rain[i][j] >= 2) {
                cloud[i][j] = 1;
                rain[i][j] -= 2;  
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check[i][j]){
                cloud[i][j] = 0;
            }
        }
    }
}

void coordinate(pair<int, int>& moveto, int index, int& x, int& y) {
    x = ((x - 1 + moveto.second * index) % n + n) % n + 1;  
    y = ((y - 1 + moveto.first * index) % n + n) % n + 1;   
}

int main() {
    int m, answer = 0;
    cin >> n >> m;

    vector<vector<int>> rain(n + 1, vector<int>(n + 1));
    vector<vector<int>> cloud(n + 1, vector<int>(n + 1, 0));

    // 초기 구름 위치 설정
    cloud[n][1] = 1;
    cloud[n][2] = 1;
    cloud[n - 1][1] = 1;
    cloud[n - 1][2] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> rain[i][j];
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        q.push({d, s});
    }

    while (!q.empty()) {
        pair<int, int> nowmove = q.front(); 
        pair<int, int> moveto = makemove[nowmove.first-1]; 
        q.pop();

        vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));
        vector<pair<int, int>> movecloud;

        // 구름 이동 및 비내리기
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cloud[i][j] == 1) {
                    int x = j, y = i;
                    coordinate(moveto, nowmove.second, x, y);
                    movecloud.push_back({y, x}); 
                    cloud[i][j] = 0; 
                    check[y][x] = true; 
                }
            }
        }

        
        for (const auto& pos : movecloud) {
            int yy = pos.first;
            int xx = pos.second;
            cloud[yy][xx] = 1; 
            rain[yy][xx]++; 
        }

      
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cloud[i][j] == 1) {
                   
                    if (i-1 >= 1 &&i-1 <=n&& j-1 >= 1&& j-1 <=n&&rain[i-1][j-1]>0) rain[i][j] ++; 
                    if (i+1 >= 1 &&i+1 <=n&& j-1 >= 1&& j-1 <=n&&rain[i+1][j-1]>0) rain[i][j] ++ ;
                    if (i+1 >= 1 &&i+1 <=n&& j+1 >= 1&& j+1 <=n&&rain[i+1][j+1]>0)rain[i][j] ++ ;
                    if (i-1 >= 1 &&i-1 <=n&& j+1 >= 1&& j+1 <=n&&rain[i-1][j+1]>0) rain[i][j] ++ ;
                }
            }
        }

        
        makecloud(cloud, rain, check);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            answer += rain[i][j];
        }
    }
    
    cout << answer;
}
