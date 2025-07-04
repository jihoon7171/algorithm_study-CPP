#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
using namespace std;
int n,m;
vector<vector<int>>space;
int answer;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<space[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void sep(int num, vector<vector<bool>>&visited, int y, int x){
    queue<pair<int, int>>q;
    space[y][x] = num;
    visited[y][x] = true;
    q.push({y, x}); // y가 first, x가 second
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx + dx[i];
            int newy = nowy + dy[i];
            if(newx >= 0 && newx < n && newy >= 0 && newy < n && space[newy][newx] == 1 && !visited[newy][newx]){
                q.push({newy, newx});
                visited[newy][newx] = true;
                space[newy][newx] = num;
            }
        }
    }
    //print();
    //cout << "\n";
}


int main(){
    cin>>n;
    space.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>space[i][j];
        }
    }
    int num = 2;
    vector<vector<bool>>visited(n, vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]&&space[i][j] == 1){
                sep(num, visited, i, j);
                num++;
            }
        }
    }
    answer = INT_MAX;
    vector<vector<pair<int, int>>>land(num+1);
    vector<vector<bool>>checking(n, vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(space[i][j] >1){
                for(int k=0;k<4;k++){
                    int nx = j+dx[k];
                    int ny = i+dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && space[ny][nx] == 0 && !checking[ny][nx]){
                        land[space[i][j]].push_back({i,j});
                        checking[ny][nx] = true;
                    }
                }
            }
        }
    }

    for(int landn = 2; landn<num;landn++){
        vector<vector<int>>dist(n, vector<int>(n, -1));
        queue<pair<int, int>>q;
        for( auto p : land[landn]){
            int y = p.first;
            int x = p.second ;
            dist[y][x] = 0;
            q.push({y,x});
        }
        bool flag = false;
        while(!q.empty() && !flag){
            auto p = q.front(); q.pop();
            int nowy = p.first;
            int nowx = p.second;
            for(int i=0;i<4;i++){
                int nx = nowx+dx[i];
                int ny = nowy+dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n ){
                    continue;
                }
                if(space[ny][nx] == landn) continue;
                if(space[ny][nx] != landn && space[ny][nx] > 0){
                    answer = min(dist[nowy][nowx], answer);
                    flag = true;
                }
                if(space[ny][nx] == 0 && dist[ny][nx] == -1){
                    dist[ny][nx]  = dist[nowy][nowx]+1;
                    q.push({ny,nx});
                }
            }
        }
    }
    cout<<answer;
}

