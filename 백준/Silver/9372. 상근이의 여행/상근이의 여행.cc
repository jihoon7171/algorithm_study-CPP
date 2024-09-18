#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

int bfs(int start, vector<vector<int>>& flight) {
    queue<int> q;
    int count = 0;
    q.push(start);
    vector<int> checking(n + 1, 0);
    checking[start] = 1;  
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        
       
        for (int i = 0; i < flight[temp].size(); i++) {
            if (checking[flight[temp][i]] == 0) {  
                count++;
                checking[flight[temp][i]] = 1; 
                q.push(flight[temp][i]); 
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  

    int a;
    cin >> a;

    for (int i = 0; i < a; i++) {
        cin >> n >> m; 
        vector<vector<int>> flight(n + 1); 
        
      
        for (int i = 0; i < m; i++) {
            int temp, go;
            cin >> temp >> go;
            flight[temp].push_back(go);
            flight[go].push_back(temp);
        }
        
        int minans = 10000;
        
    
        for (int i = 1; i <= n; i++) {
            minans = min(minans, bfs(i, flight));
        }
        
        cout << minans << "\n";  
    }

    return 0;
}
