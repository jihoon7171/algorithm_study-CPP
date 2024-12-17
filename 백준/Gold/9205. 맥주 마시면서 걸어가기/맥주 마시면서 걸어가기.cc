#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int t, n;

bool bfs(vector<vector<int>>& songdo) {
    queue<int> q;
    q.push(0); 
    vector<bool> visited(n + 2, false); 
    visited[0] = true;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        
        if (now == n + 1) {
            return true;
        }
        
       
        for (int i = 0; i < songdo[now].size(); i++) {
            if (!visited[songdo[now][i]]) {
                visited[songdo[now][i]] = true;
                q.push(songdo[now][i]);
            }
        }
    }
    return false;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;  
    while (t--) {
        cin >> n;  
        vector<pair<int, int>> conv(n + 2); 
        vector<vector<int>> songdo(n + 2);  
        
   
        for (int i = 0; i < n + 2; i++) {
            cin >> conv[i].first >> conv[i].second;
        }
        
      
        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                int distance = abs(conv[i].first - conv[j].first) + abs(conv[i].second - conv[j].second);
                if (distance <= 1000) {  
                    songdo[i].push_back(j);
                    songdo[j].push_back(i);
                }
            }
        }
        
       
        if (bfs(songdo)) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
    }
    return 0;
}