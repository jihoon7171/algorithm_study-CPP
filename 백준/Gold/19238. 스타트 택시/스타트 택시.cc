#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int n,m,gas;
vector<vector<int>>space;
pair<int, int> taxi;
vector<pair<int, int>> destination;
vector<pair<int, int>> customer;
vector<bool>finish;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

bool go_destination(int nowc);

bool find_customer(){
    vector<vector<int>>visited(n, vector<int>(n, -1));
    visited[taxi.first][taxi.second] = 0;
    queue<pair<int, int>>q;
    q.push({taxi.first, taxi.second});
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&space[ny][nx]!=1&&visited[ny][nx]== -1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    int d = INT_MAX;
    int nowc = -1;
    int gox = -1,goy = -1;
    for(int i=0;i<m;i++){
        if(finish[i] ) continue;
        int nowx = customer[i].second;
        int nowy = customer[i].first;
        if(visited[nowy][nowx] == -1) continue;
        if(visited[nowy][nowx] < d && gas > visited[nowy][nowx]){
            gox = nowx;
            goy = nowy;
            d = visited[nowy][nowx];
            nowc= i ;
        }else if(visited[nowy][nowx] == d && gas > visited[nowy][nowx]){
            if(nowy < goy){
                gox = nowx;
                goy = nowy;
                d = visited[nowy][nowx];     
                nowc = i;
            }else if(nowy == goy){
                if(nowx < gox){
                    gox = nowx;
                    goy = nowy;
                    d = visited[nowy][nowx];
                    nowc = i;
                }
            }
        }
    }
    if(gox == -1 && goy == -1){
        return false;  
    }
    gas -= visited[goy][gox];
    taxi.second = gox;
    taxi.first = goy;

    if(!go_destination(nowc)){
        return false;
    }
    return true;
}


bool checking(){
    for(int i=0;i<m;i++){
        if(!finish[i]) return false;
    }
    return true;
}

bool go_destination(int nowc){
    vector<vector<int>>visited(n, vector<int>(n, -1));
    visited[taxi.first][taxi.second] = 0;
    queue<pair<int, int>>q;
    q.push({taxi.first, taxi.second});
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&space[ny][nx]!=1&&visited[ny][nx]== -1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    int gox = destination[nowc].second;
    int goy = destination[nowc].first;
    if(visited[goy][gox] == -1){
        return false;
    }
    if(visited[goy][gox] <= gas){
        gas += visited[goy][gox];
        taxi.second = gox;
        taxi.first = goy;
        finish[nowc] = true;
        if(checking()){
            cout<<gas;
            exit(0);
        }
        return true;
    }
    return false;
}

int main() {
    cin>>n>>m>>gas;
    space.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>space[i][j];
        }
    }
    customer.resize(m);
    destination.resize(m);
    finish.resize(m);
    int a,b;
    cin>>a>>b;
    //y,x
    taxi.first = a-1;
    taxi.second = b-1;
    for(int i=0;i<m;i++){
        int cy,cx,dy,dx;
        cin>>cy>>cx>>dy>>dx;
        customer[i] = {cy-1,cx-1};
        destination[i] = {dy-1,dx-1};
    }
    while(1){
        if(!find_customer()){
            cout<<-1;
            return 0;
        }
    }
}
